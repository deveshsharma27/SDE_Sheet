class Solution {
    public int countNice(int [] nums , int k){
     if(k<0) return 0;

     int l=0, r=0;
     int sum=0, cnt=0;

     while(r<nums.length){
        sum = sum + (nums[r]%2);  // % ->change number into 0/1 

        while(sum > k){
            sum = sum - (nums[l]%2);
            l = l+1;
        }
        cnt = cnt + (r-l+1);
         r = r+1;
     }
     return cnt;
    }
    public int numberOfSubarrays(int[] nums, int k) {
       //pattern -> make into binary subarray and count sum <= goal 

       return countNice(nums , k)-countNice(nums,k-1);
    }
}