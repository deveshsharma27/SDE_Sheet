class Solution {
    public int lengthOfLongestSubstring(String s) {

        HashSet<Character> set = new HashSet<>();
        int maxlen = 0;
        int l = 0, r = 0;

        while (r < s.length()) {
            while (set.contains(s.charAt(r))) {
                set.remove(s.charAt(l));
                l = l + 1;
            }

            set.add(s.charAt(r));
            maxlen = Math.max(maxlen , r-l+1);
            r = r + 1;
        }
        return maxlen;
    }
}