class Solution {
public:
    string say(string s){
    //--(freq ,number)
     if(s.size()==0) return "1";
       int len = s.size();
       string ans ="";

       for(int i =0; i<len; i++){
            int cnt = 1;

            while( i<len-1 && s[i]==s[i+1]){
                cnt++;
                i++;
            }
             ans += to_string(cnt); // 3
            ans+= s[i]; //2
           //32 -> 3 is 2 times
       }
       return ans;
    }
    string countAndSay(int n) {
       string ans = "";
       while(n--){
       ans =  say(ans);
       }  
       return ans;
    }
};