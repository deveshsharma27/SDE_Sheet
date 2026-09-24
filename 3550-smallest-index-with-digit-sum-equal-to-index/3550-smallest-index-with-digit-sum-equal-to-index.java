class Solution {
    public int smallestIndex(int[] nums) {
        int n = nums.length;
        if (nums[0] == 0)
            return 0;

        int minIndex = Integer.MAX_VALUE;

        for (int i = 0; i < n; i++) {
            int num = nums[i];
            int sum = 0;
            while (num > 0) {

                int d = num % 10;

                sum += d;

                num /= 10;
            }
            if (sum == i) {
                minIndex = Math.min(minIndex, i);
            }
        }
        if (minIndex == Integer.MAX_VALUE)
            return -1;
        return minIndex;
    }
}