class Solution {
    public int totalNumbers(int[] digits) {
        
        // Step 1: Count digit frequencies in input
        int[] freq = new int[10];
        for (int d : digits) {
            freq[d]++;
        }

        int totalCount = 0;

        // Step 2: Iterate through all possible 3-digit even numbers
        for (int num = 100; num <= 998; num += 2) {
            int d1 = num / 100;
            int d2 = (num / 10) % 10;
            int d3 = num % 10;

            // Step 3: Count digit occurrences needed for the current number
            int[] required = new int[10];
            required[d1]++;
            required[d2]++;
            required[d3]++;

            // Step 4: Validate against available digit frequencies
            boolean possible = true;
            for (int i = 0; i < 10; i++) {
                if (required[i] > freq[i]) {
                    possible = false;
                    break;
                }
            }

            if (possible) {
                totalCount++;
            }
        }

        return totalCount;
    }
}