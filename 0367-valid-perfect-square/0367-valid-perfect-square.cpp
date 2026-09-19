class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num < 2) {
            return num;
        }

        long long left = 1;
        long long right = num / 2;

     

        while (left <= right) {
            long long mid = left + (right - left) / 2;

            if (mid * mid == num) {
               
                return true;
            } else if (mid * mid < num) {
                left = mid + 1;

            } else {
                right = mid - 1;
            }
        }
        return false;
    }
};