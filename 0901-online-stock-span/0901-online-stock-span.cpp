class StockSpanner {
public:
/*Intitution behind this Questions is basically  compute PGE and substract current ind*/

//store ->{value ,index}
stack<pair<int, int>>st;
int ind=-1;

    StockSpanner() {
        ind=-1;
    }
    
    int next(int price) {
        ind =ind+1;

        //cal---PGE Monotonic stack--
        while(!st.empty() && st.top().first <= price){
            st.pop();
        }

        int ans =( ind - (st.empty()? -1:st.top().second));
        st.push({price, ind});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */