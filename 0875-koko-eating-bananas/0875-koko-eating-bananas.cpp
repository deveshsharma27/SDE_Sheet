class Solution {
public:
// find maximum element in entire Array
    int FindMaxElement(vector<int>& piles) {
        int maxi = INT_MIN;
        int n = piles.size();
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, piles[i]);
        }
        return maxi;
    }
    // calculate Totalhours
    long long CalcTotalHours(vector<int>& piles, int hourly) {
     long long totalH = 0;
        int n = piles.size();

        for (int i = 0; i < n; i++) {
            totalH += ceil((double)piles[i] / (double)hourly); // typecast
        }
        return totalH;
    }

// back to questions
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1, high= FindMaxElement(piles);
        int ans=INT_MAX;

        while(low<=high)
        {
            int mid=(low+high)/2;
            long long totalH=CalcTotalHours(piles,mid);

            if(totalH<=(long long)h){
                ans=mid;
                high=mid-1;

            }
            else{
                low=mid+1;
            }
        }
        return ans;

    }
};