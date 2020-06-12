//
// Created by valentina on 4/6/20.
//

#ifndef BINARYTREESEARCHTEMPLATE_BSTNODE_H
#define BINARYTREESEARCHTEMPLATE_BSTNODE_H

template <typename Type>
class BSTNode {

    private:
        BSTNode<Type>* left;
        BSTNode<Type>* right;
        BSTNode<Type>* parent;
        Type key;
        int balanceFactor;

    public:
        BSTNode(Type key);
        Type getKey();
        BSTNode<Type>* getLeft();
        BSTNode<Type>* getRight();
        BSTNode<Type>* getParent();
        int getBalanceFactor();
        void setBalanceFactor(int balanceFactor);
        void setKey(Type key);
        void setLeft(BSTNode<Type>* left);
        void setRight(BSTNode<Type>* right);
        void setParent(BSTNode<Type>* parent);
        bool isLeaf();
        bool onlyRightChildren();
        bool onlyLeftChildren();
};

/* ------------------------------- Public Methods ------------------------------- */
template <typename Type>
BSTNode<Type>:: BSTNode(Type key) {
    this->key = key;
    left = NULL;
    right = NULL;
    parent = NULL;
    balanceFactor = 0;
}

/////////////////////////////////////////////
template <typename Type>
Type BSTNode<Type>:: getKey() {
    return key;
}

/////////////////////////////////////////////
template <typename Type>
BSTNode<Type>* BSTNode<Type>:: getLeft() {
    return left;
}

/////////////////////////////////////////////
template <typename Type>
BSTNode<Type>* BSTNode<Type>:: getRight() {
    return right;
}

/////////////////////////////////////////////
template <typename Type>
BSTNode<Type>* BSTNode<Type>:: getParent() {
    return parent;
}

/////////////////////////////////////////////
template <typename Type>
int BSTNode<Type>:: getBalanceFactor() {
    return balanceFactor;
}

/////////////////////////////////////////////
template <typename Type>
void BSTNode<Type>:: setBalanceFactor(int balanceFactor) {
    this->balanceFactor = balanceFactor;
}

/////////////////////////////////////////////
template <typename Type>
void BSTNode<Type>:: setKey(Type key) {
    this->key = key;
}

/////////////////////////////////////////////
template <typename Type>
void BSTNode<Type>:: setLeft(BSTNode<Type>* left) {
    this->left = left;
}


/////////////////////////////////////////////
template <typename Type>
void BSTNode<Type>:: setRight(BSTNode<Type>* right) {
    this->right = right;
}

/////////////////////////////////////////////
template <typename Type>
void BSTNode<Type>:: setParent(BSTNode<Type>* parent) {
    this->parent = parent;
}

/////////////////////////////////////////////
template <typename Type>
bool BSTNode<Type>:: isLeaf() {
    return (right == NULL && left == NULL);
}

/////////////////////////////////////////////
template <typename Type>
bool BSTNode<Type>:: onlyLeftChildren() {
    return (right == NULL && left != NULL);
}

/////////////////////////////////////////////
template <typename Type>
bool BSTNode<Type>:: onlyRightChildren() {
    return (right != NULL && left == NULL);
}
/* ------------------------------------------------------------------------------ */

#endif //BINARYTREESEARCHTEMPLATE_BSTNODE_H
