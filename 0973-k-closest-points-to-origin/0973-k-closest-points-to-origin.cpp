class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        priority_queue<pair<int, vector<int>>> pq;

        for (auto point : points) {

            int x = point[0];
            int y = point[1];

            int distance = x * x + y * y;

            pq.push({distance, point});

            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<vector<int>> result;

        while (!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }
};