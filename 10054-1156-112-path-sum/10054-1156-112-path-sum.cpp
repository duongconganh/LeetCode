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
 bool ans;
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root){
            return false;
        }
        ans = false;
        checksum(root, root->val, targetSum);
        return ans;
    }
    void checksum(TreeNode* root,int sum, int target){
        if(ans == true){
            return;
        }
        if(!root->left && !root->right){
            if(sum == target){
                ans = true;
            }
            return;
        }
        if(root->left){
            checksum(root->left, sum + root->left->val,target);
        }
        if(root->right){
            checksum(root->right, sum + root->right->val,target);
        }
    }
};