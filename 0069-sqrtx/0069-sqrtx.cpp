class Solution {
public:
    int mySqrt(int x) {
       long long ans =0;

       for(long long i =1; i<INT_MAX; i++){
            long long sq = (1LL)*(i*i);
            if(sq==x){
                ans = i;
                break;
            }else if(sq>x){
                ans = i-1;
                break;
            }
       }
      return ans; 
    }
};