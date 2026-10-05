class Solution {
public:
    int scoreOfParentheses(string s) {

        int score = 0;
        stack<int> st;
        st.push(0);

        for (char c : s) {
            if (c == '(') {
                st.push(0);
            } else {
                int innnerloop = st.top();
                st.pop();

                int outloop = max(2*innnerloop , 1);

                st.top() +=outloop;
            }
        }
        return st.top();
    }
};