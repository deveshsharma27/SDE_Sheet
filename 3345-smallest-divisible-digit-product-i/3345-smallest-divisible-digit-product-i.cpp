class Solution {
public:
    int smallestNumber(int n, int t) {

        for (int cur = n; cur <= n + 10; ++cur) {

            int product = 1;
            int temp = cur;
            while (temp) {
                int digit = temp % 10;
                product = product * digit;
                temp /= 10;
            }

            if (product % t == 0) {
                return cur;
            }
        }

        return -1;
    }
};