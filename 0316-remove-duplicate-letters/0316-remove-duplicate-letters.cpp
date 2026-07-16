class Solution {
public:
    string removeDuplicateLetters(string s) {
       vector<int>lastIndex(26,0);
       vector<bool>visited(26,false);

       string result = "";

       for(int i=0; i<s.length(); i++){        //last occurrence index of each character
        lastIndex[s[i]-'a']=i;
       } 
       
       for(int i=0; i<s.length();i++){
          char c = s[i];

          if(visited[c-'a']) continue;

        //Maintain the monotonic property:
          while(!result.empty() && result.back()> c && lastIndex[result.back()-'a']>i){
            visited[result.back() - 'a'] = false;
            result.pop_back();
          }
        result.push_back(c);
        visited[c - 'a'] = true;
       }
          return result;
    }
};