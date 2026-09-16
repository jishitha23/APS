class Solution {
public:
    
    void preorder(TreeNode* root, vector<int>& ans) {
        
        if (root == NULL)
            return;
        
        // Root
        ans.push_back(root->val);
        
        // Left
        preorder(root->left, ans);
        
        // Right
        preorder(root->right, ans);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        
        vector<int> ans;
        
        preorder(root, ans);
        
        return ans;
    }
};