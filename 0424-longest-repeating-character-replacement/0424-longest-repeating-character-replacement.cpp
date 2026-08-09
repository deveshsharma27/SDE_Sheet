class Solution {
public:
    int characterReplacement(string s, int k) {

        int l = 0;
        int r = 0;
        int maxLen = 0;
        int maxFre = 0;
        int hash[26] = {0};

        while (r < s.length()) {
            hash[s[r] - 'A']++;
            maxFre = max(maxFre, hash[s[r] - 'A']);

            if ((r - l + 1) - maxFre > k) {
                hash[s[l] - 'A']--;
                
                l++;
            }
            if ((r - l + 1) - maxFre <= k) {
                maxLen = max(maxLen, (r - l + 1));
                r++;
            }
        }

        return maxLen;
    }
};