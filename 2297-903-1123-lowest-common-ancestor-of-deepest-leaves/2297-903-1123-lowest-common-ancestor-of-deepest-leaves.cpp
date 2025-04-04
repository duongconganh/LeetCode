class Solution {
    TreeNode* ans;
    int d;
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        ans = root;
        d = 0;
        vs(root,0);
        return ans;
    }
    int vs(TreeNode* root,int depth){
        if(!root){
            return depth;;
        }
        int a = vs(root -> left, depth + 1);
        int b = vs(root -> right,depth + 1);
        if(a == b && a >= d){
            ans = root;
            d = a;
        }
        return max(a,b);
        
    }
};