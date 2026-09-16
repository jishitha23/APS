class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root,
                                   TreeNode* p,
                                   TreeNode* q) {

        // If root is NULL
        if (root == NULL)
            return NULL;

        // If root is p or q
        if (root == p || root == q)
            return root;

        // Search in left subtree
        TreeNode* left = lowestCommonAncestor(root->left, p, q);

        // Search in right subtree
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // p and q found on different sides
        if (left != NULL && right != NULL)
            return root;

        // If only left has a result
        if (left != NULL)
            return left;

        // If only right has a result
        return right;
    }
};