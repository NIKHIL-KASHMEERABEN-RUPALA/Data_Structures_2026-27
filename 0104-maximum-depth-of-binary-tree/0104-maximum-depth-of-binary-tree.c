/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) {
    
    // edge case depicting that null tree has max height 0
    if (root==NULL){
        return 0;
    }
    int leftmax = maxDepth(root->left);
    int rightmax = maxDepth(root->right);

    return(leftmax>rightmax ? leftmax : rightmax)+1 ;
}