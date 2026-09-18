class Solution {
public:
    int reverseBits(int n) {
        int temp = n;

        string s = "";

        for(int i=0; i<32; i++){
            int bit = temp%2;
            s.push_back(bit +'0');

            temp/=2;
        }

        cout<<s<<endl;

        string decimal = "";
        
        temp = stoul(s , nullptr , 2); // unsigned long integer
        // for(int i=0; i<32; i++){
        //     int deci = temp%10;
        //     decimal.push_back(deci +'a');

        //     temp/=10;
        // }

        // cout<<temp;

        return  temp;
    }
};