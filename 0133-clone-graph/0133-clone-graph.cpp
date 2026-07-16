/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* dfs(Node* cur, unordered_map<Node*, Node*>& mp) {
        vector<Node*> neighbours;
        Node* clone = new Node(cur->val);
        mp[cur] = clone;

        for (auto it : cur->neighbors) {
            if (mp.find(it) != mp.end()) {           ////already clone and stored in map
               
                neighbours.push_back(mp[it]);             /// // directly push into neighbours vector(clone)
            } else {
                neighbours.push_back(dfs(it, mp));
            }
        }
        clone->neighbors = neighbours;
        return clone;
    }
    Node* cloneGraph(Node* node) {
        // traverse all the node and cloned it.
        // use hashmap to store old / cloned node
        unordered_map<Node*, Node*> mp;
        if (node == NULL)
            return NULL;
        // if only one node present no neighbors
        if (node->neighbors.size() == 0) {
            Node* clone = new Node(node->val);
            return clone;
        }

        return dfs(node, mp);
    }
};