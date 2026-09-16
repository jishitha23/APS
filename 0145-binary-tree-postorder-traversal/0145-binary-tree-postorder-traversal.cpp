class Solution {
public:
    
    void postorder(TreeNode* root, vector<int>& ans) {
        
        if (root == NULL)
            return;
        
        // Left
        postorder(root->left, ans);
        
        // Right
        postorder(root->right, ans);
        
        // Root
        ans.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        
        vector<int> ans;
        
        postorder(root, ans);
        
        return ans;
    }
};