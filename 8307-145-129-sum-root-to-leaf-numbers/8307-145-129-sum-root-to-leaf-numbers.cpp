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
 int sum;
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if(!root){
            return 0;
        }
        sum = 0;
        number(root,0);
        return sum;
    }
    void number(TreeNode* root,int n){
        if(!root){
            return;
        }
        if(!root->left && !root->right){
            sum += (n*10 + root->val);
            return;
        }
        number(root->left, n*10 + root->val);
        number(root->right,n*10 + root->val);

    }
};