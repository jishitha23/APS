class Solution {
public:

    void dfs(TreeNode* root, string path, vector<string>& ans) {

        // If node is NULL
        if (root == NULL)
            return;

        // Add current node to path
        path += to_string(root->val);

        // If it is a leaf
        if (root->left == NULL && root->right == NULL) {
            ans.push_back(path);
            return;
        }

        // Add arrow before going to children
        path += "->";

        // Go left
        dfs(root->left, path, ans);

        // Go right
        dfs(root->right, path, ans);
    }

    vector<string> binaryTreePaths(TreeNode* root) {

        vector<string> ans;

        dfs(root, "", ans);

        return ans;
    }
};