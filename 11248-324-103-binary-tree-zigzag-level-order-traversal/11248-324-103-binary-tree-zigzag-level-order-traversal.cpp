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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root){
            return ans;
        }
        queue<TreeNode*> q;
        TreeNode* temp;
        q.push(root);
        int level = 1;
        int n;
        vector<int> p;
        while(!q.empty()){
            n = q.size();
            p.clear();
            for(int i = 0;i < n;i ++){
                temp = q.front();
                p.push_back(temp->val);
                q.pop();
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }                
            }
            if(level % 2 == 0){
                reverse(p.begin(),p.end());
            }
            ans.push_back(p);
            level ++;
        }
        return ans;        
    }        
};