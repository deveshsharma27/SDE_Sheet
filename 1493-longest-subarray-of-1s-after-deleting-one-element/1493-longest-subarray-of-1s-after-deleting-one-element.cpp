class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = 0;

        int maxLen = 0;
        int zeros = 0;

        while (right < n && left < n) {
            if (nums[right] == 0) {
                zeros++;
            }

            while (zeros > 1) {
                if (nums[left] == 0) {
                    zeros--;
                }
                left++;
            }

            maxLen = max(maxLen , right- left);

            right++;
        }
        return maxLen;
    }
};