class Solution {
    public int minimumDeletions(int[] nums) {

        int n = nums.length;
        int minIdx = 0;
       
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[minIdx]) {
                minIdx = i;
            }
        }

         int maxIdx = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[maxIdx]) {
                maxIdx = i;
            }
        }

        int i = Math.min(minIdx, maxIdx);
        int j = Math.max(minIdx, maxIdx);

        int front = j + 1;
        int back = n - i;

        int both = (i + 1) + (n - j);

        int ans = Math.min(front, Math.min(back, both));

        return ans;
    }
}