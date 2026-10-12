#include <vector>

class Solution {
public:
    int maxSum(std::vector<int>& nums, int k) {
        int MOD = 1e9 + 7;
        std::vector<int> count(32, 0);
        
        // Count the number of set bits at each position for all numbers
        for (int num : nums) {
            for (int i = 0; i < 32; ++i) {
                if ((num >> i) & 1) {
                    count[i]++;
                }
            }
        }
        
        long long ans = 0;
        
        // Greedily construct k maximum possible numbers
        for (int i = 0; i < k; ++i) {
            long long val = 0;
            for (int j = 0; j < 32; ++j) {
                if (count[j] > 0) {
                    val |= (1LL << j); // Set the j-th bit
                    count[j]--;        // Decrement the available count for this bit
                }
            }
            // Add the square of the constructed number to the answer
            ans = (ans + (val * val) % MOD) % MOD;
        }
        
        return ans;
    }
};