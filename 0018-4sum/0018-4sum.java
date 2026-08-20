class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        int n = nums.length;
        Arrays.sort(nums);
        List<List<Integer>> ans = new ArrayList<>();
        for(int i=0; i<n-3; i++){
            if(i > 0 && nums[i]==nums[i-1]){
                continue;
            }
            for(int j=i+1; j<n-2; j++){
                if(j>i+1 && nums[j]==nums[j-1]){
                    continue;
                }

                int left = j+1;
                int right = n-1;

                long remaining = (long)target - (nums[i]+nums[j]);

                while(left<right){
                    if(nums[left] + nums[right] == remaining){
                    ans.add(Arrays.asList(
                        nums[i],
                        nums[j], 
                        nums[left],
                        nums[right]));

                        while(left<right && nums[left]==nums[left+1]) left++;
                        while(left<right && nums[right]==nums[right-1]) right--;

                        left++;
                        right--;
                    }else if(nums[left]+nums[right] < remaining ){
                        left++;
                    }else{
                        right--;
                    }
                }
            }
        }
        return ans;

    //     Set<List<Integer>>set1 = new HashSet<>();
    //     for(int i=0; i<n-3; i++){
    //         for(int j=i+1; j<n-2; j++){
    //             for(int k=j+1; k<n-1; k++){
    //                 for(int l=k+1; l<n; l++){
    //                    long sum  = nums[i] + nums[j] + nums[k] + nums[l];
    //                     if(sum == target){
    //                         set1.add(Arrays.asList(nums[i] , nums[j] , nums[k] , nums[l]));
    //                     }  
    //                 }
                    
    //             }
    //         }
    //     }
       
    // return new ArrayList<>(set1);
}
};