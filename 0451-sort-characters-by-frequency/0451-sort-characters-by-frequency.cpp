class Solution {
public:
    string frequencySort(string s) {
    //hashmap---
    unordered_map<char, int> mp;
    for(char ch : s){
       mp[ch]++;
    }
    priority_queue<pair<int,char>>pq;
    for(auto it:mp){
        int freq = it.second;
        char ch = it.first;

        pq.push({freq,ch});
    }
    
    string res = "";
    while(!pq.empty()){
        auto it = pq.top();
      res.append(it.first , it.second);
      pq.pop();
    }
    return res;
    }
};