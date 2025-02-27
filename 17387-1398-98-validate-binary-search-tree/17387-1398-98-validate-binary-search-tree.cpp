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
    int pre;
    bool check;
    bool ans;
public:
    bool isValidBST(TreeNode* root) {
        check = false;
        pre = INT_MIN;
        ans = true;
        traversal(root);
        return ans;
    }
    void traversal(TreeNode* root){
        if(!root){
            return;
        }
        traversal(root->left);

        if(check){
            if(pre >= root->val){
                ans = false;
                return;
            }
        }
        pre = root->val;
        check = true;
        traversal(root->right);
        return;
    }
};