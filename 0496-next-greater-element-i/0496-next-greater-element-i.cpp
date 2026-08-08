#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_map<int, int> mp;
        stack<int> st;

        // Find next greater element for nums2
        for (int num : nums2) {
            
            while (!st.empty() && num > st.top()) {
                mp[st.top()] = num;
                st.pop();
            }

            st.push(num);
        }

        // Remaining elements have no greater element
        while (!st.empty()) {
            mp[st.top()] = -1;
            st.pop();
        }

        // Find answers for nums1
        vector<int> ans;

        for (int num : nums1) {
            ans.push_back(mp[num]);
        }

        return ans;
    }
};