class Solution {
public:
    int reverse(int x) {
    
    bool neg = x<0;
 

    long long num = abs((long long)x);

    string str = to_string(num);
    std::reverse(str.begin(), str.end());

    long long ans = stoll(str);

    if(neg) ans = -ans;

    if (ans > INT_MAX || ans < INT_MIN)
            return 0;
    return ans;
     
    }
};