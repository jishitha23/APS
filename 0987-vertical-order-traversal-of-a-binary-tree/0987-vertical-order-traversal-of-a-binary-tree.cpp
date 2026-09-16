class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        // column -> (row, value)
        map<int, vector<pair<int, int>>> mp;
        
        queue<pair<TreeNode*, pair<int, int>>> q;
        
        // node, row, column
        q.push({root, {0, 0}});
        
        while (!q.empty()) {
            
            auto current = q.front();
            q.pop();
            
            TreeNode* node = current.first;
            int row = current.second.first;
            int col = current.second.second;
            
            mp[col].push_back({row, node->val});
            
            // Left child
            if (node->left != NULL) {
                q.push({node->left, {row + 1, col - 1}});
            }
            
            // Right child
            if (node->right != NULL) {
                q.push({node->right, {row + 1, col + 1}});
            }
        }
        
        vector<vector<int>> ans;
        
        for (auto &entry : mp) {
            
            vector<pair<int, int>> nodes = entry.second;
            
            // Sort by row first, then value
            sort(nodes.begin(), nodes.end());
            
            vector<int> column;
            
            for (auto &p : nodes) {
                column.push_back(p.second);
            }
            
            ans.push_back(column);
        }
        
        return ans;
    }
};