class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        // Count frequency
        for (int x : nums) {
            freq[x]++;
        }

        // Bucket: index = frequency
        vector<vector<int>> bucket(nums.size() + 1);

        for (auto p : freq) {
            bucket[p.second].push_back(p.first);
        }

        vector<int> ans;

        // Take elements from highest frequency
        for (int i = nums.size(); i >= 1 && ans.size() < k; i--) {
            for (int x : bucket[i]) {
                ans.push_back(x);

                if (ans.size() == k)
                    break;
            }
        }

        return ans;
    }
};