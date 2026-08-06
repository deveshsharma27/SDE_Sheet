class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_set<char> set1;
        int maxlen = 0;
        int l = 0, r = 0;
        while (r < n) {

            while (set1.contains(s[r])) {
                set1.erase(s[l]);
                l = l + 1;
            }
            set1.insert(s[r]);
            maxlen = max(maxlen, r - l + 1);
            
            r = r + 1;
        }
        return maxlen;
    }
};