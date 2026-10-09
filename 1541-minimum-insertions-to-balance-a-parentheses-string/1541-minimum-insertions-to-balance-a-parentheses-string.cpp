class Solution {
public:
    int minInsertions(string s) {
        int ans = 0;
        int req = 0; // Number of ')' required

        for (char c : s) {
            if (c == '(') {
                // If we need an odd number of ')', we must complete the previous pair
                if (req % 2 != 0) {
                    ans++;
                    req--;
                }
                // A new '(' always requires two ')'
                req += 2;
            } else {
                // We found a ')'
                req--;
                // If req is negative, we need to insert a '('
                if (req < 0) {
                    ans++;
                    req += 2; // Inserted '(' requires 2 ')', but we just used 1, so req becomes 1
                }
            }
        }
        
        // Add any remaining required ')' to the insertions
        return ans + req;
    }
};