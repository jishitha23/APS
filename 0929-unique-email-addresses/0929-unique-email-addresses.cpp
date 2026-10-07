class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {

        unordered_set<string> uniqueEmails;

        for (string email : emails) {

            string local = "";
            string domain = "";

            int at = email.find('@');

            // Get local name
            local = email.substr(0, at);

            // Get domain
            domain = email.substr(at + 1);

            // Process local name
            string cleanLocal = "";

            for (char c : local) {

                if (c == '+')
                    break;

                if (c != '.')
                    cleanLocal += c;
            }

            // Create final email
            string finalEmail = cleanLocal + "@" + domain;

            uniqueEmails.insert(finalEmail);
        }

        return uniqueEmails.size();
    }
};