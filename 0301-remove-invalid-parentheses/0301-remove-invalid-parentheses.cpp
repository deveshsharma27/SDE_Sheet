class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int left_rem = 0, right_rem = 0;
        
        // Step 1: Calculate the exact number of misplaced '(' and ')'
        for (char c : s) {
            if (c == '(') {
                left_rem++;
            } else if (c == ')') {
                if (left_rem > 0) {
                    left_rem--;
                } else {
                    right_rem++;
                }
            }
        }
        
        vector<string> result;
        dfs(s, 0, left_rem, right_rem, result);
        return result;
    }

private:
    void dfs(string s, int start, int left_rem, int right_rem, vector<string>& result) {
        // Base case: If no more parentheses to remove, check if valid
        if (left_rem == 0 && right_rem == 0) {
            if (isValid(s)) {
                result.push_back(s);
            }
            return;
        }
        
        // Explore removals
        for (int i = start; i < s.length(); ++i) {
            // Pruning 1: Skip consecutive identical characters to avoid duplicate results
            if (i > start && s[i] == s[i - 1]) continue;
            
            // Pruning 2: Only attempt to remove if we have remaining removals of that type
            if (left_rem > 0 && s[i] == '(') {
                // Create a new string with the current character removed
                dfs(s.substr(0, i) + s.substr(i + 1), i, left_rem - 1, right_rem, result);
            }
            if (right_rem > 0 && s[i] == ')') {
                dfs(s.substr(0, i) + s.substr(i + 1), i, left_rem, right_rem - 1, result);
            }
        }
    }

    bool isValid(const string& s) {
        int count = 0;
        for (char c : s) {
            if (c == '(') count++;
            else if (c == ')') count--;
            if (count < 0) return false; // More closing than opening brackets at this point
        }
        return count == 0;
    }
};