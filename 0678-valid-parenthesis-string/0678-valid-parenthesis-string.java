class Solution {
    Boolean[][] memo;

    public boolean validations(String s, int ind, int cnt) {
        if (cnt < 0) return false;
        if (ind == s.length()) return cnt == 0;
        
        // If we've already solved for this index and count, return the cached result
        if (memo[ind][cnt] != null) return memo[ind][cnt];

        boolean isValid = false;
        if (s.charAt(ind) == '(') {
            isValid = validations(s, ind + 1, cnt + 1);
        } else if (s.charAt(ind) == ')') {
            isValid = validations(s, ind + 1, cnt - 1);
        } else { // It's a '*'
            isValid = validations(s, ind + 1, cnt + 1) || 
                      validations(s, ind + 1, cnt - 1) || 
                      validations(s, ind + 1, cnt);
        }
        
        // Save the result before returning
        return memo[ind][cnt] = isValid;
    }

    public boolean checkValidString(String s) {
        // Initialize the memoization table
        memo = new Boolean[s.length()][s.length() + 1];
        return validations(s, 0, 0);
    }
}