class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.length();
        int maxlen = 0;
        int l = 0, r = 0;
        unordered_map<char, int> mp;

        while (r < n) {

            mp[s[r]]++;

            while (mp[s[r]] > 2) {
                mp[s[l]]--;
                if (mp[s[l]] == 0) {
                    mp.erase(s[l]);
                }
                l++;
            }

            maxlen = max(maxlen, r - l + 1);

            r++;
        }
        return maxlen;
    }
};