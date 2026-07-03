class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.size() < needle.size()){
            return -1;
        }
         int n= haystack.size();

         for(int i =0; i<=n - needle.size(); i++){
            
            int j=0;

            while(j<needle.size() && (i+j) < haystack.size()){
                if(needle[j]!=haystack[i+j]){
                    break;
                }

                j = j+1;
            }

            if(j==needle.size()){
                return i;
            }
         }
         return -1;
    }
};