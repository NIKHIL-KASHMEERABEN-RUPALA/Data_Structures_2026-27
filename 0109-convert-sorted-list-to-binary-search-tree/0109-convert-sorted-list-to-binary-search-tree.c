/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode *buildBST(int *nums , int left , int right){
    if(left>right) return NULL;
    int mid = left+(right-left)/2;
    struct TreeNode *root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = nums[mid];
    root->left = buildBST(nums,left,mid-1);
    root->right = buildBST(nums,mid+1,right);
    return root;
}




struct TreeNode* sortedListToBST(struct ListNode* head) {
    if(!head){
        return NULL;
    }

    // leet code has maximum 20000 nodes limit as per 16th august 2026 - when i am solving this question

    int nums[20000];
    int size = 0;
    while(head){
        nums[size++]= head->val;
        head = head->next;
        // this while loop is for making array elements 
    }

    return buildBST(nums,0,size-1);
}