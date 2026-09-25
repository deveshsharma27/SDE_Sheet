class Solution {
    public int maxProduct(int[] nums) {
        
        int n = nums.length;
        long maxSum = nums[0];

        long prefix=1;
        long suffix =1;

        for(int i=0; i<n; i++){

            if(prefix ==0) prefix =1;
            if(suffix ==0) suffix=1;

            prefix *= nums[i];
            suffix  *=nums[n-1-i];

            maxSum = Math.max(maxSum , Math.max(prefix , suffix));
        }

        return (int)maxSum;
    }
}