class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!= t.size()) return false;

        int hashmap[26] = {0};
        for( char  ch : s){
            hashmap[ch-'a']++;
        }

        for( char  ch : t){
            int ind = ch-'a';

            if(hashmap[ind]==0){
                return false;
            }else{
                hashmap[ind]--;
            }
        }
        return true;
    }
};