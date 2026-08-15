class Solution {
    public int countNumOfSubarray(int[] nums, int goal) {
        if (goal < 0)
            return 0;

        int l = 0, r = 0;
        int sum = 0, cnt = 0;

        while (r < nums.length) {
            sum += nums[r];

            while (sum > goal) {
                sum = sum - nums[l];
                l = l + 1;
            }
            cnt = cnt + (r - l + 1);
            r = r + 1;
        }
        return cnt;
    }

    public int numSubarraysWithSum(int[] nums, int goal) {
        //Modify problems into ->Number of Subarray where sum<= goal
        //sum = goal -> func(arr , goal) - func(arr , goal-1);

        return countNumOfSubarray(nums, goal) - countNumOfSubarray(nums, goal - 1);
    }
}