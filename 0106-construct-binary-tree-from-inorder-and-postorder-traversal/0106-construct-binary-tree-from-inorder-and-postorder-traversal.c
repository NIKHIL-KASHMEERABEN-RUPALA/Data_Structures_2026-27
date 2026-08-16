#include <stdlib.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* createNode(int info) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = info;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct TreeNode* helper(int* inorder, int* inIdx, int* postorder, int* postIdx, int stopVal) {
    if (*postIdx < 0 || *inIdx < 0 || inorder[*inIdx] == stopVal) {
        return NULL;
    }

    // 1. Read root from postorder and decrement the value inside postIdx
    int rootVal = postorder[(*postIdx)--];
    struct TreeNode* root = createNode(rootVal);

    // 2. Build right subtree first
    root->right = helper(inorder, inIdx, postorder, postIdx, rootVal);

    // 3. Decrement the value inside inIdx
    (*inIdx)--;

    // 4. Build left subtree
    root->left = helper(inorder, inIdx, postorder, postIdx, stopVal);

    return root;
}

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    if (inorderSize == 0 || postorderSize == 0) return NULL;

    int inIdx = inorderSize - 1;
    int postIdx = postorderSize - 1;

    return helper(inorder, &inIdx, postorder, &postIdx, 3001);
}