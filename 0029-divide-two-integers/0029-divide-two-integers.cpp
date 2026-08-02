class Solution {
public:
    int divide(int dividend, int divisor) {
        
        // Handle edge case for integer overflow
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        if (dividend == divisor) return 1;

        // Determine result sign
        bool sign = (dividend < 0) == (divisor < 0);

        // Convert to 64-bit unsigned/long long to avoid abs(INT_MIN) overflow
        long long n = abs((long long)dividend);
        long long d = abs((long long)divisor);
        long long quotient = 0;

        // Bitwise division logic
        while (n >= d) {
            int cnt = 0;
            while (n >= (d << (cnt + 1))) {
                cnt++;
            }
            quotient += (1LL << cnt);
            n -= (d << cnt);
        }

        return sign ? quotient : -quotient;
    }
};