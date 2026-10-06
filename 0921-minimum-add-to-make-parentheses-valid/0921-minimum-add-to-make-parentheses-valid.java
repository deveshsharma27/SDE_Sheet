class Solution {
    public int minAddToMakeValid(String s) {

        int n = s.length();

        int cnt = 0 ,ans=0;

        for (int i = 0; i < n; i++) {
            char c = s.charAt(i);

            if (c == '(')
                cnt++;
            else {
                
                cnt--;
            }

            if(cnt < 0){
                ans++;
                cnt=0;
            }

        }
        return ans+ Math.abs(cnt);
    }
}