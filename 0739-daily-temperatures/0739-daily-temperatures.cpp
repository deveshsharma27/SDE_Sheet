class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        /*Intituations behind this problems is to calculate next greater element
         * and curr index to cal warmer temperatures*/
        stack<int> st; //--index store
        int n = temperatures.size();
        vector<int> ans(n,0);
        for (int i = 0; i < n; i++) {

            while (!st.empty() && temperatures[st.top()] < temperatures[i]) {
                ans[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};