class Solution {
public:
    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for (auto& it : invocations) {
            adj[it[0]].push_back(it[1]);
        }

        vector<int> vis(n,0);

        // suspicious nodes starting from node k using BFS
        queue<int> q;
        q.push(k);
        vis[k] = 1;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto& it : adj[node]) {
                if (!vis[it]) {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }

        // Check if any non-suspicious node invokes a suspicious node
        for (auto& it : invocations) {
            int u = it[0];
            int v = it[1];


        //An outside node calls a suspicious method,
        // so we cannot remove any suspicious methods 
        
            if (!vis[u] && vis[v]) {
                vector<int> ans(n);
                for (int i = 0; i < n; i++) {
                    
                    ans[i] = i;
                }
                 return ans;
            }
           
        }

        //remaining node with No suspecius--
        vector<int>methode;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                methode.push_back(i);
            }
        }
        return methode;
    }
};