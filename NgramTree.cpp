#include <string>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <queue>
using namespace std;

#include "NgramTree.h"

NgramTree::NgramTree()
{
    this->root = NULL;
}

NgramTree::~NgramTree()
{
}

int NgramTree::getTotalNgramCount()
{
    int totalNgram = 0;
    traverseNgramCounts( this->root, totalNgram);
    return totalNgram;
}

void NgramTree::traverseNgramCounts(NgramNode *node, int& count)
{
    if ( node == NULL ) return;

    traverseNgramCounts( node->left, count);
    count++;
    traverseNgramCounts( node->right, count);
}

void NgramTree::printNgramFrequencies()
{
    traverseFrequencies( this->root );
}

void NgramTree::traverseFrequencies(NgramNode *node)
{
    if( node == NULL ) return;

    traverseFrequencies( node->left );
    cout << "\"" << node->data << "\" appears " << node->count << " time(s)." << endl;
    traverseFrequencies( node->right );
}

bool NgramTree::isComplete()
{
    /*
        My approach is do BFS using queue and count the no of nodes.
        Run a loop till the queue is not null but break once you find one of the below condition holds good:
        left node is not present for a node
        left node is present but right node is not present.

        Now we can compare the count that we get from the above approach and the original
        count of the nodes in the tree. If both equal then complete binary tree else not.
    */

    queue<NgramNode*> q;
    q.push(this->root);

    int nodeCount = 0;
    for( NgramNode *tmp = q.front(); tmp != NULL; nodeCount++)
    {
        cout << "in node: " << tmp->data << endl;

        if(tmp->left == NULL || (tmp->left != NULL && tmp->right == NULL) )
            break; //if left node is missing and right node is existing, cannot be complete tree

        q.push(tmp->left);
        q.push(tmp->right);
        q.pop();



        tmp = q.front();
    }

    return (nodeCount == this->getTotalNgramCount() ) ? true : false;
}

NgramNode* NgramTree::getRoot()
{
    return this->root;
}

void NgramTree::generateTree(string fileName, int n)
{
    //string text = "this is sample text \nand thise is all";

    string text("");
    string line;
    ifstream myFile("sample.txt");

    if (myFile.is_open())
    {
      while ( getline(myFile, line) )
      {
        text.append(line);
      }
      myFile.close();
    }
    else
    {
        cout << "Unable to open file" << endl;
        return;
    }

    for(int i = 0; i < text.length(); i++)
    {
        string tmp = "";
        for(int j = 0; j < n; j++)
        {
            if(i+j < text.length())  //if the string size is not exceeded
                tmp += text.at(i+j);

        }

        cout << tmp << endl;
        std::size_t found;
        if( (tmp.length() != n) ||
            ( (found = tmp.find(' ') ) != string::npos) ||
            ( (found = tmp.find('\n') ) != string::npos) ) //npos is -1, if it contains empty space OR length is not equal to n, just ignore it
            continue;

        this->addNgram(tmp);
    }
}

NgramNode* NgramTree::getNewNode(string data)
{
    NgramNode* newNode = new NgramNode();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void NgramTree::print(NgramNode *current, int indent)
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

void NgramTree::addNgram(string data)
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


NgramNode* NgramTree::insertRecursion(NgramNode* node, string data)
{
    if( node == NULL)
    {
        node = getNewNode(data);
        node->count++;
    }
    else if (  data.compare(node->data) == 0 )
    {
        node->count++; // if strings are equal increment frequency
    }
    else if ( data.at(0) <= node->data.at(0) ) //if less or equal, insert to left
    {
        node->left = this->insertRecursion(node->left, data);
    }
    else //if greater, insert to right
    {
        node->right = this->insertRecursion(node->right, data);
    }

    return node;
}

NgramNode* NgramTree::search(string data)
{
    return this->searchRecursion( this->root, data);
}

NgramNode* NgramTree::searchRecursion(NgramNode* node, string data)
{
    if( node == NULL ) return node;

    if( data.at(0) == node->data.at(0) )
        return node;
    else if( data.at(0) <= node->data.at(0) )
        return this->searchRecursion( node->left, data);
    else
        return this->searchRecursion( node->right, data);
}



void NgramTree::removeIterative(string data)
{
    NgramNode *node = this->root;
    NgramNode *parent = NULL;

    while( node != NULL ) //if the node is not still found, keep traversing
    {
        if ( data.at(0) < node->data.at(0) )
        {
            // keep traverse
            parent = node;
            node = node->left;
        }
        else if ( data.at(0) > node->data.at(0) )
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

                NgramNode *tmp = node->right;
                NgramNode *tmpParent = node;

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

NgramNode* NgramTree::removeRecursion(NgramNode* node, string data)
{
    if(node == NULL) return NULL;
    else if ( data.at(0) < node->data.at(0) ) node->left = removeRecursion( node->left, data);
    else if ( data.at(0) > node->data.at(0) ) node->right = removeRecursion( node->right, data);
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
            NgramNode *tmp = node;
            node = node->right;
            delete tmp;
        }
        else if ( node->right == NULL )
        {
            // if it has ONE child and LEFT
            NgramNode *tmp = node;
            node = node->left;
            delete tmp;
        }
        else
        {
            // if it has TWO child
            NgramNode *tmp = this->findMin(node->right);
            node->data = tmp->data;
            node->right = this->removeRecursion(node->right, tmp->data);
        }
        return node;
    }
}

NgramNode* NgramTree::findMax(NgramNode* root)
{
    if( root == NULL ) return NULL;
    if(root->right == NULL) return root;

    findMax(root->right);
}

NgramNode* NgramTree::findMin(NgramNode *root)
{
    if( root == NULL ) return NULL;
    if(root->left == NULL) return root;

    findMin(root->left);
}
