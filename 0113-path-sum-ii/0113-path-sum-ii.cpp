class Solution {
public:

    void dfs(TreeNode* root, int targetSum,
             vector<int>& path,
             vector<vector<int>>& ans) {

        // Empty node
        if (root == NULL)
            return;

        // Add current node to path
        path.push_back(root->val);

        // If current node is a leaf
        if (root->left == NULL && root->right == NULL) {

            // Check if sum is equal
            if (targetSum == root->val) {
                ans.push_back(path);
            }

            // Remove current node
            path.pop_back();
            return;
        }

        // Go to left subtree
        dfs(root->left, targetSum - root->val, path, ans);

        // Go to right subtree
        dfs(root->right, targetSum - root->val, path, ans);

        // Backtracking
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

        vector<vector<int>> ans;
        vector<int> path;

        dfs(root, targetSum, path, ans);

        return ans;
    }
};