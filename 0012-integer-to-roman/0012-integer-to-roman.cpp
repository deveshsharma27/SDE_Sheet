class Solution {
public:
    string intToRoman(int num) {
      //---1050 - 1000= 50(L)
      //----ML
       
//Store the Roman symbols in descending order along with their values.
 vector<pair<int, string>> roman = {
            {1000, "M"},
            {900, "CM"},
            {500, "D"},
            {400, "CD"},
            {100, "C"},
            {90, "XC"},
            {50, "L"},
            {40, "XL"},
            {10, "X"},
            {9, "IX"},
            {5, "V"},
            {4, "IV"},
            {1, "I"}
        };

   
      string res;
      for(auto &it:roman){
        while(num >= it.first){
            res += it.second;
            num -= it.first;
        }
      }
     return res;
    }
};