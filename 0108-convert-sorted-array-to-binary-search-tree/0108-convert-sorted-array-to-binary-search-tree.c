/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode *buildTree(int *nums , int left , int right){
    if(left>right){
        return NULL;
    }

    // now i will pick up the middle element 
    int mid = (left+right)/2;
    struct TreeNode *root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = nums[mid];
    root->left = buildTree(nums , left , mid-1);
    root->right = buildTree(nums , mid+1 , right);
    return root;
}
struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    return buildTree(nums,0,numsSize-1);
}