class Solution {
    public int maxSubArray(int[] nums) {

        int n = nums.length;

        int ans = Integer.MIN_VALUE;

        long sum = 0;

        for (int i = 0; i < n; i++) {

            sum += nums[i];

            if (sum > ans) {
                ans = (int)sum;
            }

            if (sum < 0) {
                sum = 0;
            }
        }
        return ans;
    }
}