class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int mul = 1;
        int num = n;
        while (num) {
            int digit = num % 10; 

            sum += digit;
            mul = mul * digit;

            num = num / 10; 
        }

        if (n % (sum + mul) != 0)
            return false;

        return true;
    }
};