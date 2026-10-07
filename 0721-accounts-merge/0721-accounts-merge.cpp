class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a != b)
            parent[b] = a;
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        int n = accounts.size();

        // Initialize DSU
        parent.resize(n);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        // email -> account index
        unordered_map<string, int> emailMap;

        // Connect accounts having common emails
        for (int i = 0; i < n; i++) {

            for (int j = 1; j < accounts[i].size(); j++) {

                string email = accounts[i][j];

                if (emailMap.find(email) != emailMap.end()) {
                    unite(i, emailMap[email]);
                }
                else {
                    emailMap[email] = i;
                }
            }
        }

        // Group emails according to root account
        unordered_map<int, vector<string>> groups;

        for (auto& entry : emailMap) {

            string email = entry.first;
            int accountIndex = entry.second;

            int root = find(accountIndex);

            groups[root].push_back(email);
        }

        // Create result
        vector<vector<string>> result;

        for (auto& group : groups) {

            int root = group.first;

            vector<string> emails = group.second;

            sort(emails.begin(), emails.end());

            vector<string> account;

            // Add name
            account.push_back(accounts[root][0]);

            // Add sorted emails
            for (string email : emails) {
                account.push_back(email);
            }

            result.push_back(account);
        }

        return result;
    }
};