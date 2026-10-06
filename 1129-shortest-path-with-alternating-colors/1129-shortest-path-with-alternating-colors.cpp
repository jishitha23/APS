class Solution {
public:
    vector<int> shortestAlternatingPaths(
        int n,
        vector<vector<int>>& redEdges,
        vector<vector<int>>& blueEdges) {

        vector<vector<int>> red(n), blue(n);

        for (auto e : redEdges)
            red[e[0]].push_back(e[1]);

        for (auto e : blueEdges)
            blue[e[0]].push_back(e[1]);

        // dist[node][color]
        // color 0 = red, color 1 = blue
        vector<vector<int>> dist(n, vector<int>(2, -1));

        queue<pair<int, int>> q;

        // Start with both possible colors
        dist[0][0] = 0;
        dist[0][1] = 0;

        q.push({0, 0});
        q.push({0, 1});

        while (!q.empty()) {
            auto [node, color] = q.front();
            q.pop();

            int nextColor = 1 - color;

            vector<vector<int>>& graph =
                (nextColor == 0) ? red : blue;

            for (int next : graph[node]) {
                if (dist[next][nextColor] == -1) {
                    dist[next][nextColor] =
                        dist[node][color] + 1;

                    q.push({next, nextColor});
                }
            }
        }

        vector<int> answer(n);

        for (int i = 0; i < n; i++) {
            if (dist[i][0] == -1)
                answer[i] = dist[i][1];
            else if (dist[i][1] == -1)
                answer[i] = dist[i][0];
            else
                answer[i] = min(dist[i][0], dist[i][1]);
        }

        return answer;
    }
};