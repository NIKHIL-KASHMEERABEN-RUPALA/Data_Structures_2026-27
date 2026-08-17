/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {

private:
    TreeNode *prev= nullptr;
    int currCount = 0;
    int maxCount = 0;
    std::vector<int> modes;

    void inOrder(TreeNode* node){
        if(!node){
            return;
        }
        inOrder(node->left);
        if(prev && prev->val == node->val){
            currCount++;
        }
        else{
            currCount = 1;
        }
        if(currCount>maxCount){
            maxCount = currCount;
            modes.clear();
            modes.push_back(node->val);
        }else if(currCount==maxCount){
            modes.push_back(node->val);
        }
        prev = node;
        inOrder(node->right);
    }



public:
    vector<int> findMode(TreeNode* root) {
        prev = nullptr;
        currCount = 0;
        maxCount = 0;
        modes.clear();
        inOrder(root);
        return modes;
    }
};