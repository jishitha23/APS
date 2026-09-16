class Solution {
public:

    int diameter = 0;

    int height(TreeNode* root) {

        // Empty node has height 0
        if (root == NULL)
            return 0;

        // Find left height
        int left = height(root->left);

        // Find right height
        int right = height(root->right);

        // Diameter passing through current node
        diameter = max(diameter, left + right);

        // Return height of current node
        return 1 + max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) {

        height(root);

        return diameter;
    }
};