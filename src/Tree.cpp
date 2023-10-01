//
// Created by Kaylee Briggs on 9/30/23.
//
#include "Tree.h"
#include <queue>

//TODO: Make traversals not have ending comma
//TODO: removeInOrderN
//TODO: remove
//TODO: tests, regex, documentation. . . the rest


void Tree::remove(string ufid) {

}

Node* Tree::searchIdHelper(Node* root, string ufid) {
    if (root == nullptr) {
        cout << "unsuccessful";
        return nullptr;
    }
    else if (stoi(ufid) == stoi(root->ufid)){
       cout << root->name << endl;
       return root;
    }
    else if (stoi(ufid) < stoi(root->ufid)){
        root->left = searchIdHelper(root->left, ufid);
    }
    else if (stoi(ufid) > stoi(root->ufid)){
        root->right = searchIdHelper(root->right,  ufid);
    }
    return root;
}

Node* Tree::searchNameHelper(Node* root, string name) {
    if(root != nullptr) {
        if (name == root->name){
            cout << root->ufid + ", ";
        }
        searchNameHelper(root->left, name);
        searchNameHelper(root->right, name);
    }
    // TODO: need to add unsuccessful condition
    return root;
}

Node* Tree::printInOrderHelper(Node *root) {
    if(root != nullptr) {
        printInOrderHelper(root->left);
        cout << root->name + ", ";
        printInOrderHelper(root->right);
    }
    return root;
}

Node* Tree::printPreOrderHelper(Node *root) {
    if(root != nullptr) {
        cout << root->name + ", ";
        printPreOrderHelper(root->left);
        printPreOrderHelper(root->right);
    }
    return root;
}

Node* Tree::printPostOrderHelper(Node *root) {
    if (root != nullptr){
        printPostOrderHelper(root->left);
        printPostOrderHelper(root->right);
        cout << root->name + ", ";
    }
    return root;
}

// Code is taken from Bridges Programming Quiz
Node* Tree::printLevelCountHelper(Node *root) {
    if (root == nullptr) {
        cout << 0;
        return nullptr;
    }
    queue<Node*> q;
    q.push(root);
    int count = 0;
    while (!q.empty()){
        int levelSize = q.size();
        for (int i = 0; i < levelSize; i++) {
            Node *node = q.front();
            q.pop();

            // Enqueue the children for the next level
            if (node->left != nullptr) {
                q.push(node->left);
            }
            if (node->right != nullptr) {
                q.push(node->right);
            }
        }
        count++;
    }
    cout << count;
    return nullptr;
}

void Tree::removeInOrderN(Node *root) {

}

Node *Tree::rotateLeft(Node *node) {
    Node* rightChild = node->right;
    node->right = rightChild->left;
    rightChild->left = node;

    // Update heights of the rightChild and node
    node->height = 1 + max(node->left ? node->left->height : 0, node->right ? node->right->height: 0);
    rightChild->height = 1 + max(rightChild->left ? rightChild->left->height : 0, rightChild->right ? rightChild->right->height: 0);
    return rightChild;
}

Node *Tree::rotateRight(Node *node) {
    Node* leftChild = node->left;
    node->left = leftChild->right;
    leftChild->right = node;

    // Update heights of the leftChild and node
    node->height = 1 + max(node->left ? node->left->height : 0, node->right ? node->right->height: 0);
    leftChild->height = 1 + max(leftChild->left ? leftChild->left->height : 0, leftChild->right ? leftChild->right->height: 0);
    return leftChild;
}

Node *Tree::rotateLeftRight(Node *node) {
    node->left = rotateLeft(node->left);
    return rotateRight(node);
}

Node *Tree::rotateRightLeft(Node *node) {
    node->right = rotateRight(node->right);
    return rotateLeft(node);
}

int Tree::getBalanceFactor(Node* root){

    // Find left and right factors, take difference for balance factor
    int lFactor = (root->left ? root->left->height: 0);
    int rFactor = (root->right ? root->right->height: 0);
    int bFactor = lFactor-rFactor;
    return bFactor;
}

Node *Tree::insertHelper(Node *root, string name, string ufid) {
    if (root == nullptr) {
        cout << "successful" << endl;
        return new Node(name, ufid);
    }
    else if (stoi(ufid) < stoi(root->ufid)){
        root->left = insertHelper(root->left, name, ufid);
    }
    else if (stoi(ufid) > stoi(root->ufid)){
        root->right = insertHelper(root->right, name, ufid);
    }
    else {
        cout << "unsuccessful";
    }
    root->height = 1 + max(root->left ? root->left->height : 0, root->right ? root->right->height: 0);

    // Left heavy case
    if (getBalanceFactor(root) == 2){
        if (getBalanceFactor(root->left) == -2){
            // Perform left right rotation
            return rotateLeftRight(root);
        }
        else {
            // Perform right rotation
            return rotateRight(root);
        }
    }

    // Right heavy case
    else if (getBalanceFactor(root) == -2){
        if (getBalanceFactor(root->right) == 2) {
            // Perform right left rotation
            return rotateRightLeft(root);
        }
        else {
            // Perform left rotation
            return rotateLeft(root);
        }
    }
    return root;
}

