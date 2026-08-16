#include <stdlib.h>
#include <limits.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

static struct TreeNode* helper(int* preorder, int preorderSize, int* preIdx,
                               int* inorder, int inorderSize, int* inIdx, 
                               int stopVal) {
    // Stop if all elements consumed OR we hit the inorder boundary for the current subtree
    if (*preIdx >= preorderSize || inorder[*inIdx] == stopVal) {
        return NULL;
    }

   
    int rootVal = preorder[(*preIdx)++];
    struct TreeNode* root = createNode(rootVal);

    // Build left subtree: stops when inorder reaches rootVal
    root->left = helper(preorder, preorderSize, preIdx, inorder, inorderSize, inIdx, rootVal);

    // Left subtree finished -> advance inorder pointer past rootVal
    (*inIdx)++;

    // Build right subtree: stops at whatever stopped the current root
    root->right = helper(preorder, preorderSize, preIdx, inorder, inorderSize, inIdx, stopVal);

    return root;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    if (preorderSize == 0 || inorderSize == 0) return NULL;

    int preIdx = 0;
    int inIdx = 0;

    
    // LeetCode node values are between -3000 and 3000
    return helper(preorder, preorderSize, &preIdx, inorder, inorderSize, &inIdx, 3001);
}