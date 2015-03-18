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
        this->print(current->left, indent + 4);
        if (indent > 0)
            cout << setw(indent) << " ";
        cout << current->data<< endl;
        this->print(current->right, indent + 4);
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



void BST::removeItem(int data)
{
    BstNode* toDelete = this->search(data);
}

void BST::removeRecursion(BstNode* node, int data)
{
    if(node == NULL) return;
//    if( (node->right == NULL) && (node->left != NULL) )
}

BstNode* BST::findMax(BstNode* root)
{
    if( root == NULL ) return NULL;
    if(root->right == NULL) return root;

    findMax(root->right);
}

BstNode* BST::findMin(BstNode* root)
{
    if( root == NULL ) return NULL;
    if(root->left == NULL) return root;

    findMin(root->left);
}
