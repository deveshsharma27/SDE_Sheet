class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        int n =cardPoints.size();
        int lSum =0, rSum =0;
        int maxSum =0;
// 1. Calculate sum of first k elements from the left
        for(int i=0; i<k; i++){
            lSum = lSum + cardPoints[i];
        }
        maxSum = lSum;

        int rindex=n-1;
// 2. Remove one element from left and add one from right
        for(int i =k-1; i>=0; i--){
            lSum = lSum -cardPoints[i];
            rSum = rSum + cardPoints[rindex];
            rindex--;

            maxSum = max(maxSum , lSum + rSum);
        }
        return maxSum;

    }
};