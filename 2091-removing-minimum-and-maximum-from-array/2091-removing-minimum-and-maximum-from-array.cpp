class Solution {
public:
    int minimumDeletions(vector<int>& nums) {

        int n = nums.size();
        int mx = max_element(nums.begin(), nums.end()) - nums.begin();
        int mn = min_element(nums.begin(), nums.end()) - nums.begin();

        // Delete from left to right
        int i = 0;
        int cnt = 0;
        while (i <= mx || i <= mn) {
            cnt++;
            i++;
        }
        // Delete from Right to left
        int r = n - 1;
        int cnt1=0;
        while (r >= mx || r >= mn) {
            cnt1++;
            r--;
        }
        // Delete from  LEft and Right Both side at time
        int left = 0, right = n - 1;
        int cnt2 = 0;
        
        while(left<=min(mx, mn)){
            cnt2++;
            left++;
        }

        while(right>=max(mx , mn)){
            cnt2++;
            right--;
        }

        int ans = min({cnt, cnt1, cnt2});

        return ans;
    }
};