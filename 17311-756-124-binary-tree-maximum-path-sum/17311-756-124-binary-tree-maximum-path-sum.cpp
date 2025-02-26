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
int ans;
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        ans = -99999;
        checkmax(root);
        return ans;
    }
    int checkmax(TreeNode* root){
        if(!root){
            return -99999;
        }
        int x = checkmax(root->left);
        int y = checkmax(root->right);
        int value = root->val;
        int m = max(max(x + value, y + value),value);;
        ans = max(ans,max(x + y + value,m));
        return m;
    }
};