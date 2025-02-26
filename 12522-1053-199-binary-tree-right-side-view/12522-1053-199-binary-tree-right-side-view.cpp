class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root){
            return ans;
        }
        queue<TreeNode*> q;
        TreeNode* temp;
        q.push(root);
        int n;
        int p;
        while(!q.empty()){
            n = q.size();

            for(int i = 0;i < n;i ++){
                temp = q.front();
                p = temp->val;
                q.pop();
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }                
            }
            ans.push_back(p);
        }
        return ans;             
    }
};