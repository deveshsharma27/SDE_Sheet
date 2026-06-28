class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        int flag = 0;
        vector<int> st;
        for (int i = 0; i < n; i++) {
            int x = asteroids[i];
            while (!st.empty() && st.back() > 0 && x < 0) {
                if (abs(st.back()) > abs(x)) {
                    flag = 1;
                    break;
                } else if (abs(st.back()) == abs(x)) {
                    st.pop_back();
                    flag=1;
                    break;
                } else {
                    st.pop_back();
                    continue;
                }
            }

       
            if (flag) {
                flag = 0;
                continue;
            }
             st.push_back(x);
        }

        return st;
    }
};