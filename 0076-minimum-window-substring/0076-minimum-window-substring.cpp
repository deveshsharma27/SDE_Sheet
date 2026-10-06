class Solution {
public:
    string minWindow(string s, string t) {

        int l = 0, r = 0, minLen = 1e9;
        int startInd = -1;

        int hash[256] = {0};
        int charCnt = 0;

        for (char c : t) { // O(m)
            hash[c]++;
        }

        while (r < s.size()) { // O(n)
            if (hash[s[r]] > 0)
                charCnt++;
            hash[s[r]]--; // freq decrease

            while (charCnt == t.size()) {

                if ((r - l + 1) < minLen) {
                    minLen = r - l + 1;
                    startInd = l;
                }

                hash[s[l]]++;
                if (hash[s[l]] > 0)
                    charCnt--;


                l++;
            }
            r++;
        }
        return startInd == -1 ? "" : s.substr(startInd, minLen);
    }
};