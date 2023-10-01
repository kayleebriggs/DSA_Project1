//
// Created by Kaylee Briggs on 9/30/23.
//

#ifndef PROJECT1_TREE_H
#define PROJECT1_TREE_H

#endif //PROJECT1_TREE_H

#pragma once
#include <iostream>
using namespace std;

struct Node {
    string name;
    string ufid;
    int height =1;
    Node* left;
    Node* right;
public:
    Node(string name, string ufid ) : name(""), ufid(""), left(nullptr), right(nullptr) {
        this->name = name;
        this->ufid = ufid;
    }
};
class Tree {
private:
    // Private Helper Functions
    Node* insertHelper(Node* node, string name, string ufid);
    Node* printInOrderHelper(Node* node);
    Node* printPreOrderHelper(Node* node);
    Node* printPostOrderHelper(Node* node);
    Node* printLevelCountHelper(Node* node);
    Node* searchIdHelper(Node* node, string ufid);
    Node* searchNameHelper(Node* node, string name);
public:
    Node* TreeRoot;
    Tree() : TreeRoot() {}
    void insert(string name, string ufid) {
        this->TreeRoot = insertHelper(this->TreeRoot, name, ufid);
    }
    void remove(string ufid);
    void searchId(string ufid) {
        this->TreeRoot = searchIdHelper(this->TreeRoot, ufid);
    };
    void searchName(string name) {
        this->TreeRoot = searchNameHelper(this->TreeRoot, name); };
    void printInOrder(){
        this->TreeRoot = printInOrderHelper(this->TreeRoot);
    };
    void printPreOrder(){
        this->TreeRoot = printPreOrderHelper(this->TreeRoot);
    };
    void printPostOrder(){
        this->TreeRoot = printPostOrderHelper(this->TreeRoot);
    };
    void printLevelCount(){
        this->TreeRoot = printLevelCountHelper(this->TreeRoot);
    };
    void removeInOrderN(Node* root);
    int getBalanceFactor(Node* root);
    // Rotations
    Node* rotateLeft(Node *node);
    Node* rotateRight(Node *node);
    Node* rotateLeftRight(Node *node);
    Node* rotateRightLeft(Node *node);
};