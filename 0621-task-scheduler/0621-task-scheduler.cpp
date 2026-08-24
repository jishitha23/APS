#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);

        // Count frequency of each task
        for (char task : tasks) {
            count[task - 'A']++;
        }

        // Find the maximum frequency
        int maxFreq = 0;

        for (int i = 0; i < 26; i++) {
            maxFreq = max(maxFreq, count[i]);
        }

        // Number of tasks having maximum frequency
        int maxCount = 0;

        for (int i = 0; i < 26; i++) {
            if (count[i] == maxFreq) {
                maxCount++;
            }
        }

        // Minimum intervals based on the most frequent task
        int result = (maxFreq - 1) * (n + 1) + maxCount;

        // We cannot have fewer intervals than the number of tasks
        return max((int)tasks.size(), result);
    }
};