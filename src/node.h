//
// Created by Kaylee Briggs on 9/26/23.
//

#include "node.h"

class Node{
public:
    int ufID;
    int height;
    string name;
    Node *left;
    Node *right;
    //point to UF ID
    //point to respective name

    //Necessary Functions
    Node* rotateLeft(Node *node)
    Node* rotateRight(Node *node)
    Node* rotateLeftRight(Node *node)
    void helper(Node* root, vector<int>& v)
    void preorder(Node* root)
    void inorderTraversal(TreeNode* root, vector<int>& res)
    TreeNode* constructBBST(vector<int> res, int first, int last)
};


