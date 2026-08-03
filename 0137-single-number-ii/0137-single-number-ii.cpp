class Solution {
public:
    int singleNumber(vector<int>& nums) {

        //most optimal O(nlogm)/sc-O(1) ---------
        int n =nums.size();
        sort(nums.begin(), nums.end());

        for(int i=1; i<n; i= i+3){

            if(nums[i]!=nums[i-1]){
                return nums[i-1];
            }
        }
        return nums[n-1] ; // last element is always be our answers---


        ///----brute-force --------

        // int n = nums.size();
        // unordered_map<int,int>mp;  //  num -> freq
        // for(int num: nums){
        //     mp[num]++;
        // }

        // for(auto it:mp){
        //     if(it.second==1){
        //         return it.first;
        //         break;
        //     }
        // }
        // return 0;
    }
};