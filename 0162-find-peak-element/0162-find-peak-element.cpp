class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        int n = nums.size();

        int low = 0, high = n - 1;

        while (low < high) {
            int mid = low + (high-low)/2;

            if(nums[mid] > nums[mid+1]){  // 1 2 1 3(m) 5 6 4 -> incresing slope
              high = mid;   //peak is always in right                 
            }else{
                low = mid +1; //peak is always is mid , or left
            }
        }
        return low;

        // for (int i = 0; i < n-1; i++) {
        //     if ( nums[i] > nums[i + 1]) {
        //         return i;
        //         break;
        //     }
        // }
        // return n-1; // if loops not return anythinhs thne our peak is
        // nums.size()-1;
    }
};