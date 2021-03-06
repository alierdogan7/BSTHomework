#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

#include "BST.h"

BST::BST()
{
    this->root = NULL;
}

BST::~BST()
{
}

BstNode* BST::getRoot()
{
    return this->root;
}

BstNode* BST::getNewNode(int data)
{
    BstNode* newNode = new BstNode();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void BST::print(BstNode *current, int indent)
{
    if (current != NULL)
    {
        this->print(current->right, indent + 4);
        if (indent > 0)
            cout << setw(indent) << " ";
        cout << current->data<< endl;
        this->print(current->left, indent + 4);
    }
}

void BST::insert(int data)
{
    if(this->root == NULL)
    {
        this->root = this->insertRecursion(this->root, data); //if inserting op is initial, initialize root
    }
    else
    {
        this->insertRecursion(this->root, data); //there is no need to assign anything
    }
}

BstNode* BST::insertRecursion(BstNode* node, int data)
{
    if( node == NULL)
    {
        node = getNewNode(data);
    }
    else if ( data <= node->data ) //if less or equal, insert to left
    {
        node->left = this->insertRecursion(node->left, data);
    }
    else //if greater, insert to right
    {
        node->right = this->insertRecursion(node->right, data);
    }

    return node;
}

BstNode* BST::search(int data)
{
    return this->searchRecursion( this->root, data);
}

BstNode* BST::searchRecursion(BstNode* node, int data)
{
    if( node == NULL ) return node;

    if( data == node->data)
        return node;
    else if( data <= node->data )
        return this->searchRecursion( node->left, data);
    else
        return this->searchRecursion( node->right, data);
}



void BST::removeIterative(int data)
{
    BstNode *node = this->root;
    BstNode *parent = NULL;

    while( node != NULL ) //if the node is not still found, keep traversing
    {
        if ( data < node->data )
        {
            // keep traverse
            parent = node;
            node = node->left;
        }
        else if ( data > node->data )
        {
            // keep traverse
            parent = node;
            node = node->right;
        }
        else
        {
            //if data == node->data
            if( node->right == NULL && node->left == NULL )
            {
                // if NO child
                if ( node == this->root )
                {
                    // delete the root
                    delete node;
                    node = NULL;
                }
                else
                {
                    if( parent->left == node) parent->left = NULL;
                    else if( parent->right == node ) parent->right = NULL;

                    delete node;
                    node = NULL;
                }
            }
            else if ( node->right == NULL )
            {
                //it has ONE child on LEFT
                if ( node == this->root )
                {
                    // make the root the left child of it
                    this->root = node->left;
                    delete node;
                    node = NULL;
                }
                else
                {
                    if( parent->left == node ) parent->left = node->left;
                    else if ( parent->right == node) parent->right = node->left;

                    delete node;
                    node = NULL;
                }
            }
            else if ( node->left == NULL )
            {
                // if it has ONE child on RIGHT
                if ( node == this->root )
                {
                    // make the root the right child of it
                    this->root = node->right;
                    delete node;
                    node = NULL;
                }
                else
                {
                    if( parent->left == node ) parent->left = node->right;
                    else if ( parent->right == node) parent->right = node->right;

                    delete node;
                    node = NULL;
                }
            }
            else
            {
                // if it has TWO child
                // find the min. node and its parent

                BstNode *tmp = node->right;
                BstNode *tmpParent = node;

                if ( tmp->left == NULL ) // node->right->left == NULL
                {
                    // that means the min. of this subtree is the root
                    node->data = tmp->data; //copy the min value
                    node->right = tmp->right;
                    delete tmp;
                    tmp = NULL;
                }
                else
                {
                    //that means the min in this subtree is the leftmost node of the root of the right subtree
                    while(tmp->left != NULL)
                    {
                        tmpParent = tmp;
                        tmp = tmp->left;
                    }

                    node->data = tmp->data; // copy the min. data to node
                    //min. has to be leaf, so it has certainly NO child, so we can remove the min simply
                    tmpParent->left = NULL; // cut the connection btw. min value and its parent
                    delete tmp;
                    tmp = NULL;
                }
            }
        }
    }
}

BstNode* BST::removeRecursion(BstNode* node, int data)
{
    if(node == NULL) return NULL;
    else if ( data < node->data ) node->left = removeRecursion( node->left, data);
    else if ( data > node->data ) node->right = removeRecursion( node->right, data);
    else
    {
        if ( node->left == NULL && node->right == NULL )
        {
            // if it has NO child
            delete node;
            node = NULL;
        }
        else if ( node->left == NULL )
        {
            //if it has ONE child and RIGHT
            BstNode *tmp = node;
            node = node->right;
            delete tmp;
        }
        else if ( node->right == NULL )
        {
            // if it has ONE child and LEFT
            BstNode *tmp = node;
            node = node->left;
            delete tmp;
        }
        else
        {
            // if it has TWO child
            BstNode *tmp = this->findMin(node->right);
            node->data = tmp->data;
            node->right = this->removeRecursion(node->right, tmp->data);
        }
        return node;
    }
}

BstNode* BST::findMax(BstNode* root)
{
    if( root == NULL ) return NULL;
    if(root->right == NULL) return root;

    findMax(root->right);
}

BstNode* BST::findMin(BstNode *root)
{
    if( root == NULL ) return NULL;
    if(root->left == NULL) return root;

    findMin(root->left);
}
