class Solution {
public:
    vector<int> topoSort(vector<vector<int>>& graph, vector<int>& indegree) {
        queue<int> q;

        for (int i = 0; i < graph.size(); i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> result;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            result.push_back(u);

            for (int v : graph[u]) {
                indegree[v]--;

                if (indegree[v] == 0)
                    q.push(v);
            }
        }

        if (result.size() != graph.size())
            return {};

        return result;
    }

    vector<int> sortItems(int n, int m, vector<int>& group,
                           vector<vector<int>>& beforeItems) {

        // Give a new group number to ungrouped items
        for (int i = 0; i < n; i++) {
            if (group[i] == -1)
                group[i] = m++;
        }

        // Item graph
        vector<vector<int>> itemGraph(n);
        vector<int> itemIndegree(n, 0);

        // Group graph
        vector<vector<int>> groupGraph(m);
        vector<int> groupIndegree(m, 0);

        for (int i = 0; i < n; i++) {
            for (int prev : beforeItems[i]) {

                itemGraph[prev].push_back(i);
                itemIndegree[i]++;

                // If items belong to different groups
                if (group[prev] != group[i]) {
                    groupGraph[group[prev]].push_back(group[i]);
                    groupIndegree[group[i]]++;
                }
            }
        }

        // Sort groups
        vector<int> groupOrder =
            topoSort(groupGraph, groupIndegree);

        if (groupOrder.empty())
            return {};

        // Sort items
        vector<int> itemOrder =
            topoSort(itemGraph, itemIndegree);

        if (itemOrder.empty())
            return {};

        // Put sorted items inside their groups
        vector<vector<int>> itemsInGroup(m);

        for (int item : itemOrder) {
            itemsInGroup[group[item]].push_back(item);
        }

        // Build final answer according to group order
        vector<int> answer;

        for (int g : groupOrder) {
            for (int item : itemsInGroup[g]) {
                answer.push_back(item);
            }
        }

        return answer;
    }
};