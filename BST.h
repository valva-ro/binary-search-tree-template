//
// Created by valentina on 4/6/20.
//

#ifndef BINARYTREESEARCHTEMPLATE_BST_H
#define BINARYTREESEARCHTEMPLATE_BST_H

#include "BSTNode.h"

using namespace std;

template <typename Type>
class BST {

    private:
        BSTNode<Type>* root;

    public:
        BST();
        ~BST();
        void insert(Type data);
        int getHeight();
        BSTNode<Type>* getRoot();
        BSTNode<Type>* getMaxNode(BSTNode<Type>* treeNode);
        BSTNode<Type>* getMinNode(BSTNode<Type>* treeNode);
        void deleteKey(Type key);
        void deleteAll();
        bool isBalanced();
        bool search(Type key);
        Type successor(Type key);
        Type predecessor(Type key);
        void inOrder();
        void preOrder();
        void postOrder();
        void displayData();

private:
        BSTNode<Type>* insert(BSTNode<Type>* treeNode, Type key);
        bool isBalanced(BSTNode<Type>* treeNode);
        int getHeight(BSTNode<Type>*treeNode);
        BSTNode<Type>* deleteKey(BSTNode<Type>* treeNode, Type key);
        BSTNode<Type>* deleteCaseLeaf(BSTNode<Type>* treeNode);
        BSTNode<Type>* deleteCaseOneChild(BSTNode<Type>* treeNode);
        BSTNode<Type>* deleteCaseTwoChilds(BSTNode<Type>* treeNode);
        void deleteAll(BSTNode<Type>* treeNode);
        BSTNode<Type>* search(BSTNode<Type>* treeNode, Type key);
        Type successor(BSTNode<Type>* treeNode);
        Type predecessor(BSTNode<Type>* treeNode);
        void inOrder(BSTNode<Type>* treeNode);
        void preOrder(BSTNode<Type>* treeNode);
        void postOrder(BSTNode<Type>* treeNode);
};

/* ------------------------------- Public Methods ------------------------------- */

template <typename Type>
BST<Type>:: BST() {
    root = 0;
}

////////////////////////////////////////////////
template <typename Type>
BST<Type>:: ~BST() {
    deleteAll();
}

////////////////////////////////////////////////
template <typename Type>
void BST<Type>:: insert(Type data) {
    root = insert(root, data);
}

////////////////////////////////////////////////
template <typename Type>
int BST<Type>:: getHeight() {
    return getHeight(root);
}

////////////////////////////////////////////////
template <typename Type>
BSTNode<Type>* BST<Type>:: getRoot() {
    return root;
}

////////////////////////////////////////////////
template <typename Type>
BSTNode<Type>* BST<Type>:: getMaxNode(BSTNode<Type>* treeNode) {
    if (!root) {
        cout <<  "The BST is empty!" << endl;
        return NULL;
    }
    while(treeNode->getRight())
        treeNode = treeNode->getRight();
    return treeNode;
}

////////////////////////////////////////////////
template <typename Type>
BSTNode<Type>* BST<Type>:: getMinNode(BSTNode<Type>* treeNode) {
    if (!root) {
        cout <<  "The BST is empty!" << endl;
        return NULL;
    }
    while(treeNode->getLeft())
        treeNode = treeNode->getLeft();

    return treeNode;
}

////////////////////////////////////////////////
template <typename Type>
void BST<Type>:: deleteKey(Type key) {
    root = deleteKey(root, key);
}

////////////////////////////////////////////////
template <typename Type>
void BST<Type>:: deleteAll() {
    deleteAll(root);
}

////////////////////////////////////////////////
template <typename Type>
bool BST<Type>:: isBalanced() {
    return isBalanced(root);
}

////////////////////////////////////////////////
template <typename Type>
bool BST<Type>:: search(Type key) {
    BSTNode<Type>* result = search(root, key);
    return result != NULL;
}

////////////////////////////////////////////////
template <typename Type>
Type BST<Type>::successor(Type key) {

    BSTNode<Type>* keyNode = search(root, key);

    if(keyNode == NULL)
        return -1;
    else
        return successor(keyNode);
}

////////////////////////////////////////////////
template <typename Type>
Type BST<Type>::predecessor(Type key) {

    BSTNode<Type>* keyNode = search(root, key);

    if(keyNode == NULL)
        return -1;
    else
        return predecessor(keyNode);

}

////////////////////////////////////////////////
template <typename Type>
void BST<Type>:: inOrder() {
    inOrder(root);
    cout << "\n";
}

////////////////////////////////////////////////
template <typename Type>
void BST<Type>:: preOrder() {
    preOrder(root);
    cout << "\n";
}

////////////////////////////////////////////////
template <typename Type>
void BST<Type>:: postOrder() {
    postOrder(root);
    cout << "\n";
}

////////////////////////////////////////////////
template <typename Type>
void BST<Type>:: displayData() {
    cout << "\tIn order: ";
    inOrder();
    cout << "\tPre order: ";
    preOrder();
    cout << "\tPost order: ";
    postOrder();

    cout << "\n\tThe root of this BST is: " << root->getKey() << "\n";
    cout << "\tThe height of this BST is: " << getHeight() << "\n";
    cout << "\tMax value: " << getMaxNode(root)->getKey() << "\n";
    cout << "\tMin value: " << getMinNode(root)->getKey() << "\n";

    if (isBalanced())
        cout << "\tBST is balanced! " << "\n\n";
    else
        cout << "\tBST is not balanced! " << "\n\n";

    cout << "____________________________________\n";
}

/* ------------------------------------------------------------------------------ */


/* ------------------------------- Private Methods ------------------------------ */

////////////////////////////////////////////////
template <typename Type>
BSTNode<Type>* BST<Type>:: insert(BSTNode<Type>* treeNode, Type key) {
    if (treeNode == NULL)
        treeNode = new BSTNode<Type>(key);

    else if (key > treeNode->getKey())
        treeNode->setRight(insert(treeNode->getRight(), key));

    else
        treeNode->setLeft(insert(treeNode->getLeft(), key));

    return treeNode;
}

////////////////////////////////////////////////
template<typename Type>
int BST<Type>:: getHeight(BSTNode<Type>* treeNode) {
    if (!treeNode)
        return 0;
    return 1 + max(getHeight(treeNode->getLeft()), getHeight(treeNode->getRight()));
}

////////////////////////////////////////////////
template<typename Type>
bool BST<Type>:: isBalanced(BSTNode<Type>* treeNode) {
    if (!treeNode)
        return false;
    /*
    int leftHeight = getHeight(treeNode->getLeft());
    int rightHeight = getHeight(treeNode->getRight());

    return abs(leftHeight - rightHeight) <= 1;
     */
    return getHeight(treeNode->getLeft()) == getHeight(treeNode->getRight());
}

////////////////////////////////////////////////
template<typename Type>
BSTNode<Type>* BST<Type>:: deleteCaseLeaf(BSTNode<Type>* treeNode) {
    delete treeNode;
    return NULL;
}

////////////////////////////////////////////////
template<typename Type>
BSTNode<Type>* BST<Type>:: deleteCaseOneChild(BSTNode<Type>* treeNode) {

    if (treeNode->onlyRightChildren()) {
        BSTNode<Type>* rightNode = treeNode->getRight();
        rightNode->setParent(treeNode->getParent());
        BSTNode<Type>* aux = treeNode;
        delete aux;
        return rightNode;
    }

    else if (treeNode->onlyLeftChildren()) {
        BSTNode<Type>* leftNode = treeNode->getLeft();
        leftNode->setParent(treeNode->getParent());
        BSTNode<Type>* aux = treeNode;
        delete aux;
        return leftNode;
    }
}

////////////////////////////////////////////////
template<typename Type>
BSTNode<Type>* BST<Type>:: deleteCaseTwoChilds(BSTNode<Type>* treeNode) {
    Type successorKey = successor(treeNode->getKey());
    treeNode->setKey(successorKey);
    treeNode->setRight(deleteKey(treeNode->getRight(), successorKey));
    return treeNode;
}

////////////////////////////////////////////////
template<typename Type>
BSTNode<Type>* BST<Type>:: deleteKey(BSTNode<Type>* treeNode, Type key) {

    if (treeNode == NULL)
        return NULL;

    if(treeNode->getKey() == key) {

        if (treeNode->isLeaf())
            treeNode = deleteCaseLeaf(treeNode);

        else if (treeNode->onlyRightChildren() || treeNode->onlyLeftChildren())
            treeNode = deleteCaseOneChild(treeNode);

        else
            treeNode = deleteCaseTwoChilds(treeNode);
    }

    else if (treeNode->getKey() < key)
        treeNode->setRight(deleteKey(treeNode->getRight(), key));

    else
        treeNode->setLeft(deleteKey(treeNode->getLeft(), key));

    return treeNode;
}

////////////////////////////////////////////////
template <typename Type>
void BST<Type>:: deleteAll(BSTNode<Type>* treeNode) {
    if(treeNode == NULL)
        return;
    deleteAll(treeNode->getLeft());
    deleteAll(treeNode->getRight());
    delete treeNode;
}

////////////////////////////////////////////////
template <typename Type>
BSTNode<Type>* BST<Type>:: search(BSTNode<Type> *treeNode, Type key) {
    if (treeNode == NULL || treeNode->getKey() == key)
        return treeNode;
    if (key > treeNode->getKey())
        return search(treeNode->getRight(), key);
    return search(treeNode->getLeft(), key);
}

////////////////////////////////////////////////
template<typename Type>
Type BST<Type>:: successor(BSTNode<Type>* treeNode) {

    if (!treeNode->onlyRightChildren()) {
        BSTNode<Type>* minNode = getMinNode(treeNode->getRight());
        return minNode->getKey();
    }

    BSTNode<Type>* successor = NULL;
    BSTNode<Type>* predecessor = root;

    while (predecessor != treeNode) {
        if (treeNode->getKey() < predecessor->getKey()) {
            successor = predecessor;
            predecessor = predecessor->getLeft();
        }
        else
            predecessor = predecessor->getRight();
    }
    return successor->getKey();
}

////////////////////////////////////////////////
template<typename Type>
Type BST<Type>:: predecessor(BSTNode<Type>* treeNode) {
    if (!treeNode->onlyLeftChildren())
        return getMinNode(treeNode->onlyLeftChildren());

    BSTNode<Type>* successor = NULL;
    BSTNode<Type>* predecessor = root;

    while (predecessor != treeNode) {
        if (treeNode->getKey() < predecessor->getKey()) {
            successor = predecessor;
            predecessor = predecessor->getRight();
        }
        else
            predecessor = predecessor->getLeft();
    }
    return successor->getKey();
}

////////////////////////////////////////////////
template<typename Type>
void BST<Type>:: inOrder(BSTNode<Type>* treeNode) {
    if (!treeNode)
        return;
    inOrder(treeNode->getLeft());
    cout << treeNode->getKey() << " " ;
    inOrder(treeNode->getRight());
}

/////////////////////////////////////////////////////////////////////////////////////////
template<typename Type>
void BST<Type>:: preOrder(BSTNode<Type>* treeNode) {
    if (!treeNode)
        return;
    cout << treeNode->getKey() << " ";
    preOrder(treeNode->getLeft());
    preOrder(treeNode->getRight());
}

/////////////////////////////////////////////////////////////////////////////////////////
template<typename Type>
void BST<Type>:: postOrder(BSTNode<Type>* treeNode) {
    if (!treeNode)
        return;
    postOrder(treeNode->getLeft());
    postOrder(treeNode->getRight());
    cout << treeNode->getKey() << " ";
}

/* ------------------------------------------------------------------------------ */



#endif //BINARYTREESEARCHTEMPLATE_BST_H