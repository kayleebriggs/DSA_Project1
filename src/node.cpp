//
// Created by Kaylee Briggs on 9/26/23.
//

#ifndef PROJECT1_NODE_H
#define PROJECT1_NODE_H

Node* rotateLeft(Node *node)
{
//your code here
    Node* rightChild = node->right;
    node->right = rightChild->left;
    rightChild->left = node;
    return rightChild;
}
Node* rotateRight(Node *node) {
    //your code here
    Node* leftChild = node->left;
    node->left = leftChild->right;
    leftChild->right = node;
    return leftChild;
}
Node* rotateLeftRight(Node *node)
{
//your code here
    node->left = rotateLeft(node->left);
    return rotateRight(node);
}
void helper(Node* root, vector<int>& v) {
    if (root != NULL) {
        v.push_back(root->val);
        for (int i = 0; i < (root->children).size(); i++) {
            helper((root->children)[i], v);
        }
    }
}
void preorder(Node* root) {
    vector<int> res;
    if (root == nullptr) return;
    helper(root, res);
    for (auto i : res)
        cout << i << " ";
    cout << endl;
}

void inorderTraversal(TreeNode* root, vector<int>& res) {
    if (root == nullptr)
        return;
    inorderTraversal(root->left, res);
    res.push_back(root->val);
    inorderTraversal(root->right, res);
}

TreeNode* constructBBST(vector<int> res, int first, int last) {
    if (first > last)
        return nullptr;
    int mid = (first + last)/2;

}



#endif //PROJECT1_NODE_H
