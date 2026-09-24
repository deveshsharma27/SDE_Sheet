class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n= nums.size();
        unordered_map<int, int> mpp;

        for (int num : nums) {
            mpp[num]++;
        }
         
         int res =0;
        for (int num : nums) {
            if (mpp[num] > n/2) {
               res = num;
            }
        }
        return res;
    }
};