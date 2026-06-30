class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        
        //Ignore any leading whitespace (" ").
        int start=0; 
        while(start<n && s[start]== ' '){
            start++;
        }
      // sign of integer---
      int sign = 1;
      if(start<n && s[start]=='-'|| s[start]=='+'){
        if(s[start]=='-'){
         sign =-1;
        }
         start++;
      }
      
      //conversion------
      long long ans =0;
      while(start<n && isdigit(s[start])){
      //add new digit   
        ans = ans*10 + (s[start]-'0');
         
         //check overflow---
         if(sign ==1 && ans>=INT_MAX){
            return INT_MAX;
         }
         if(sign ==-1 && (-ans) < INT_MIN){
            return INT_MIN;
         }
        start++;
      }
      return sign*ans;
    }
};