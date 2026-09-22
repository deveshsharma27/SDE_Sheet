class Solution {
    public int reverse(int x) {
        boolean neg = true;
        if (x < 0)
            neg = false;

        long num = Math.abs((long) x);

        String str = String.valueOf(num);
        String reverse = "";

        for (int i = str.length() - 1; i >= 0; i--) {

            reverse += str.charAt(i);
        }

        long res = Long.parseLong(reverse);

        if (neg == false)
            res = -res;

        if (res > Integer.MAX_VALUE || res < Integer.MIN_VALUE) {
            return 0;
        } else {
            return (int)res;
        }

    }
}