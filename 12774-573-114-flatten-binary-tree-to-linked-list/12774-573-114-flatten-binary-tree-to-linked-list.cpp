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
TreeNode* ans;
class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root){
            return;
        }
        ans = new TreeNode(0);
        TreeNode* result = ans;
        traversal(root);
        root->left = nullptr;
        root->right = result->right->right;
    }
    void traversal(TreeNode* root){
        if(!root){
            return;
        }else{
            TreeNode* newnode = new TreeNode(root->val);
            ans->right = newnode;
            ans = ans->right;

        }
        traversal(root->left);
        traversal(root->right);
    }
};