class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        // Empty tree
        if (root == NULL)
            return false;

        // If it is a leaf
        if (root->left == NULL && root->right == NULL)
            return targetSum == root->val;

        // Subtract current node value
        targetSum = targetSum - root->val;

        // Check left or right path
        return hasPathSum(root->left, targetSum) ||
               hasPathSum(root->right, targetSum);
    }
};