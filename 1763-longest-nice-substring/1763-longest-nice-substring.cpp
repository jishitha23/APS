class Solution {
public:
    string longestNiceSubstring(string s) {

        if (s.length() < 2)
            return "";

        // Check whether every character has both cases
        for (int i = 0; i < s.length(); i++) {

            char c = s[i];

            bool lower = false;
            bool upper = false;

            for (char x : s) {
                if (x == tolower(c))
                    lower = true;

                if (x == toupper(c))
                    upper = true;
            }

            // If one case is missing, split here
            if (!lower || !upper) {

                string left = longestNiceSubstring(s.substr(0, i));
                string right = longestNiceSubstring(s.substr(i + 1));

                if (left.length() >= right.length())
                    return left;
                else
                    return right;
            }
        }

        // Entire string is nice
        return s;
    }
};