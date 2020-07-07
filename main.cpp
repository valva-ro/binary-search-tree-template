#include <iostream>
#include "BST.h"

int main() {
/*
    BST<int>* myBST = new BST<int>();
    int numbers[10] = {5, 10, 3, 51, 110, 4, 1, 13, 6, 20};

    for (int i = 0; i < 10; i++)
        myBST->insert(numbers[i]);

    cout << "____________________________________\n"
            "\n\t\t        5\n"
            "\t\t     /     \\\n"
            "\t\t    3       10\n"
            "\t\t  /   \\    /  \\\n"
            "\t\t 1     4  6   51\n"
            "\t\t             /  \\\n"
            "\t\t            13   110\n"
            "\t\t              \\\n"
            "\t\t               20\n\n";
    myBST->displayData();

    cout << "\tDeleting 10...\n";
    myBST->deleteKey(10);
    cout << "\n\t\t        5\n"
            "\t\t     /     \\\n"
            "\t\t    3        51\n"
            "\t\t  /   \\     /  \\\n"
            "\t\t 1     4   13   110\n"
            "\t\t          /  \\\n"
            "\t\t         6    20\n\n";
    myBST->displayData();

    cout << "\tDeleting 3...\n";
    myBST->deleteKey(3);
    cout << "\n\t\t        5\n"
            "\t\t     /     \\\n"
            "\t\t    4        51\n"
            "\t\t  /         /  \\\n"
            "\t\t 1         13   110\n"
            "\t\t          /  \\\n"
            "\t\t         6    20\n\n";
    myBST->displayData();
*/
    BST<int>* myBST = new BST<int>();
    int numbers[3] = {10, 20, 30}; //40, 50, 5, 15, 25, 35, 45};

    for (int i = 0; i < 3; i++)
        myBST->insert(numbers[i]);

    myBST->displayData();

    delete myBST;
    return 0;
}
