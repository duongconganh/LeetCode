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
public:
    bool isSymmetric(TreeNode* root) {
        if(!root->right && !root->left){
            return true;
        }
        bool ans = check(root->left,root->right);
        return ans;        
    }
    bool check(TreeNode* l,TreeNode* r){
        if(!l || !r){
            if(l || r){
                return false;
            }
            cout<<"?";
            return true;
        }
        if(l->val != r->val){
            return false;
        }
        bool x = check(l->left,r->right);
        bool y = check(r->left,l->right);
        return x && y;

    }
};