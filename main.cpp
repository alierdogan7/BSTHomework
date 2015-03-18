#include <iostream>
using namespace std;

#include "BST.h"

int main()
{
    BST myBst;

    myBst.insert(15);
    myBst.insert(7);
    myBst.insert(5);
    myBst.insert(12);
    myBst.insert(25);

    int id = 0;
    myBst.print(myBst.getRoot(), id);

    cout << endl << endl;

    cout << "Max: " << (myBst.findMax(myBst.getRoot()) )->data << endl;
    cout << "Min: " << (myBst.findMin(myBst.getRoot()) )->data << endl;

    cout << "\n\nData to search: ";
    int seek;
    cin >> seek;
    BstNode* foundItem;
    if( (foundItem = myBst.search(seek) ) != NULL ) cout << "\n\nFound! " <<  foundItem << "->data = " << foundItem->data << endl;
    else cout << "\n\nNot found!" << endl;

    return 0;
}
