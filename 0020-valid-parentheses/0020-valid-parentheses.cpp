class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char c : s) {

            // Opening brackets
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            }

            // Closing brackets
            else {
                if (st.empty()) {
                    return false;
                }

                char top = st.top();
                st.pop();

                if (c == ')' && top != '(')
                    return false;

                if (c == '}' && top != '{')
                    return false;

                if (c == ']' && top != '[')
                    return false;
            }
        }

        // Stack should be empty at the end
        return st.empty();
    }
};