class Solution {
public:
    int check;
    int ans;
    int pre = -1;
    int kthSmallest(TreeNode* root, int k) {
        ans = 0;
        check = 0;
        traversal(root,k);
        return ans;        
    }
    void traversal(TreeNode* root, int k){
        if(!root){
            return;
        }
        traversal(root->left,k);
        check++;
        if(check == k){
            ans = root->val;
            return;
        }
        traversal(root->right,k);

    }
};