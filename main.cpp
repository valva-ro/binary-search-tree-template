#include <iostream>
#include "BST.h"

int main() {

    BST<int>* myBST = new BST<int>();

    myBST->insert(5);
    myBST->insert(10);
    myBST->insert(3);
    myBST->insert(51);
    myBST->insert(110);
    myBST->insert(4);
    myBST->insert(1);
    myBST->insert(13);

    cout << "____________________________________\n"
            "\n\t\t        5\n"
            "\t\t     /     \\\n"
            "\t\t    3       10\n"
            "\t\t  /   \\      \\\n"
            "\t\t 1     4      51\n"
            "\t\t             /  \\\n"
            "\t\t            13   110\n\n";
    myBST->displayData();

    cout << "\tDeleting 10...\n";
    myBST->deleteKey(10);
    cout << "\n\t\t        5\n"
            "\t\t     /     \\\n"
            "\t\t    3       51\n"
            "\t\t  /   \\    /  \\\n"
            "\t\t 1     4  13   110\n\n";
    myBST->displayData();

    cout << "\tDeleting 3...\n";
    myBST->deleteKey(3);
    cout << "\n\t\t        5\n"
            "\t\t     /     \\\n"
            "\t\t    4       51\n"
            "\t\t  /        /   \\\n"
            "\t\t 1        13   110\n\n";
    myBST->displayData();

    delete myBST;
    return 0;
}
