class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        if (s.size() < k)
            return "";

        string ans = "";
        int cnt = 0;

        int left = 0;
        int right = 0;
        while (right < s.length()) {

            cnt += s[right] - '0';

            while (left <= right && (cnt > k || s[left] == '0')) {
                cnt -= s[left] - '0';
                left++;
            }
            if (cnt == k) {
                string t = s.substr(left, right - left + 1);

                if (ans == "" || t.length() < ans.length() ||
                    t.length() == ans.length() && t < ans) {
                    ans = t;
                }
            }
            right++;
        }
        return ans;
    }
};