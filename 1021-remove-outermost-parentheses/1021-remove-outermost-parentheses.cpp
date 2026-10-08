class Solution {
public:
    string removeOuterParentheses(string s) {

        string ans = "";
        int cnt = 0;
        for (char c : s) {
            if (c == '(') {
                if (cnt > 0) {
                    ans.push_back(c);
                }
                cnt++;
            }else{
                cnt--;

                if(cnt>0){
                    ans.push_back(c);
                }
            }
        }
        return ans;
    }
};