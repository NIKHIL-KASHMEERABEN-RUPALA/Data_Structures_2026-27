/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode *createNode(int val){
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int findInorderIndex(int *inorder , int left , int right , int value){
    for(int i = left ; i<=right ; i++){
        if(inorder[i]==value){
            return i;
        }
    }
    return -1;
}

struct TreeNode *helper(int *preorder, int *preOrderIndex , int *inorder , int left , int right){
    if(left>right){
        return NULL;
    }
    int rootVal = preorder[*preOrderIndex];
    (*preOrderIndex)++;
    struct TreeNode *root = createNode(rootVal);

    int inorderIndex = findInorderIndex(inorder,left,right,rootVal);

    root->left = helper(preorder , preOrderIndex , inorder , left ,inorderIndex-1);
    root->right = helper(preorder,preOrderIndex,inorder,inorderIndex+1,right);
    return root;
}



struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    int preorderIndex = 0;
    return helper(preorder,&preorderIndex , inorder, 0 , inorderSize-1);
}