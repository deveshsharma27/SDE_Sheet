class Solution {
public:
    int search(vector<int>& nums, int target) {
        
    //      nums = [4,5,6,7,0,1,2] , target = 0;


    //      index ->0 4 !=0
    //             ->1 5!=0;
    //             ->2 6->0
    //             ->3 7!=0;
    //             ->4 0=0;
    //             return in as 4;

    //             time complecxity = o(m);
    //             space O(1);

    //     nums = [4,5,6,7,0,1,2], target =0;
        
    //     low =0 high = 6
    //     mid = 0+6/2 = 3;

    //    low = mid +1= 4  , high = 6
    //    mid = 4+6/2=5

    //    nums[mid] = 1;
    //    high = mid-1=4; low = 4;
    //    mid = 8/2=4;

    //    nums[mid]=0;

    //    ans =4;

    //    time complexity = O(logn)
    //    space o(1)



    int low =0;
    int high = nums.size()-1;
    
    while(low<=high){
        int mid = low + (high-low)/2;

        if(nums[mid]==target){
            return mid;
        }

        if(nums[low] <= nums[mid]){
            if(nums[low]<= target && target<= nums[mid]){
                high = mid -1;
            }else{
                low = mid+1;

            }
        }
        else{
            if(nums[mid ] <= target && target <=nums[high]){
                low = mid +1;
            }else{
                high = mid-1;
            }
        }
    }
    return -1;

    }
};