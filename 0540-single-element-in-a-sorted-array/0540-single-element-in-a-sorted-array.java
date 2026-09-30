class Solution {
    public int singleNonDuplicate(int[] nums) {
        
        int n = nums.length;

        int low =0, high= n-2; // to prevent out of bounds if last elemnt is ans

        while(low<=high){
            int mid = low + (high-low)/2;

            if(nums[mid]==nums[mid^1]){
               // mid^1 -> mid+1 if even pair
               low = mid +1; 
            }else{
                //mid^1 -> mid-1 if odd pair
                high = mid-1;
            }
        }

        return nums[low];
    }
}