class Solution {
public:
        int subarrayKDistinct(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int l = 0, r = 0;
        int cnt = 0;
        while (r < nums.size()) {
            mp[nums[r]]++;

            while (mp.size() > k) {
                mp[nums[l]]--;

                if (mp[nums[l]] == 0) {
                    mp.erase(nums[l]);
                }

                l = l + 1;
            }

                cnt += r-l+1;
            
            r++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
       return subarrayKDistinct(nums, k) - subarrayKDistinct(nums ,k-1);
    }
};