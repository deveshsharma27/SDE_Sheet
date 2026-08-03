class Solution {
public:
    int minBitFlips(int start, int goal) {
        if(start == goal) return 0;

        int num = start ^goal ;
        //count number of  set bit ---
        int cnt =0;
        for(int i=0; i<31; i++){
            if(num & ( 1<<i)){
                cnt++;
            }
        }
        return cnt;
    }
};