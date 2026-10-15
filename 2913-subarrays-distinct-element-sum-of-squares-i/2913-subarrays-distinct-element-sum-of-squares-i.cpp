class Solution {
public:
    int sumCounts(vector<int>& nums) {

        int ans = 0;

        for (int i = 0; i < nums.size(); i++) {

            unordered_set<int> distinctNumbers;

            for (int j = i; j < nums.size(); j++) {

                distinctNumbers.insert(nums[j]);

                int count = distinctNumbers.size();

                ans += count * count;
            }
        }
        return ans;
    }
};