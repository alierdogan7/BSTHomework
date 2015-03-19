/*#include <iostream>
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

    int option;

    do {
        cout << "Enter the data to insert to BST (exiting is -1): ";
        cin >> option;

        if(option != -1)
        {
            myBst.insert(option);
            cout << "The root of the BST is: " << (myBst.getRoot())->data << endl;
            myBst.print(myBst.getRoot(), id);
        }


    } while( option != -1);

    do {
        cout << "Enter the data to delete from BST (exiting is -1): ";
        cin >> option;

        if(option != -1)
        {
            myBst.removeIterative(option);
            cout << "The root of the BST is: " << (myBst.getRoot())->data << endl;
            myBst.print(myBst.getRoot(), id);
        }


    } while( option != -1);

    return 0;
}
*/
