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
 int m = 0;
class Solution {
public:
    int maxDepth(TreeNode* root) {
        m = 0;
        if(root == nullptr){
            return 0;
        }
        solution(root,1);
        return m;
    }
    bool solution(TreeNode* root, int depth){
        if(!root->left&&!root->right){
            m = max(depth,m);
            return false;
        }
        if(root->right){
            solution(root->right,depth + 1);
        }

        if(root->left){
            solution(root->left,depth + 1);
        }
        return 1;
    }
};