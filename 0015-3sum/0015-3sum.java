class Solution {
    public List<List<Integer>> threeSum(int[] nums) {

        Arrays.sort(nums);
        int n = nums.length;
        List<List<Integer>> ans = new ArrayList<>();

        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int target = -nums[i];
            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                if (nums[left] + nums[right] == target) {
                    ans.add(Arrays.asList(nums[i], nums[left], nums[right]));

                    while (left < right && nums[left] == nums[left + 1])
                        left++;
                    while (left < right && nums[right] == nums[right -1])
                        right--;

                    left++;
                    right--;
                } else if (nums[left] + nums[right] < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return ans;
        // Set<List<Integer>>set1 = new HashSet<>();
        // for(int i=0; i<n-2; i++){
        //     for(int j=i+1; j<n; j++){
        //         for(int k=j+1; k<n; k++){
        //             if(nums[i]+nums[j]+nums[k]==0){
        //                 set1.add(Arrays.asList(nums[i],nums[j],nums[k]));
        //             }
        //         }
        //     }
        // }
        // return new ArrayList<>(set1);
    }
}