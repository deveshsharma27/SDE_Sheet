class Solution {
    public int maxFrequency(int[] nums, int k) {
        Arrays.sort(nums);
        int n = nums.length;
        long sum = 0;
        int l = 0, r = 0, maxFreq = 0;

        while (r < n) {
            sum += nums[r];

            while ((long) (r - l + 1) * nums[r] - sum > k) {

                sum -= nums[l];
                l++;
            }

            maxFreq = Math.max(maxFreq, r - l + 1);

            r++;

        }
        return maxFreq;
    }
}