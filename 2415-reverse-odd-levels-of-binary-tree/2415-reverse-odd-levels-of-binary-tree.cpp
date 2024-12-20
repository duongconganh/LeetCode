class Solution {
private:
    void Reverse(TreeNode* left, TreeNode* right, int level) {
        if (left == NULL || right == NULL)
            return;

        if (level % 2 != 0) {
            swap(left->val, right->val);
        }
        
        Reverse(left->left, right->right, level + 1);
        Reverse(left->right, right->left, level + 1);
    }
    
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (root == NULL) 
            return root;
        Reverse(root->left, root->right, 1);
        return root;
    }
};
