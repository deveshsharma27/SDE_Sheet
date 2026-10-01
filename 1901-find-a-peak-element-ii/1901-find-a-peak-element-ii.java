class Solution {
    public int[] findPeakGrid(int[][] mat) {
        int n = mat.length;
        int m = mat[0].length;
        int low = 0, high = m - 1;
        
        while (low <= high) {
            int midCol = low + (high - low) / 2;
            
            // Step 1: Find the row with the maximum element in the midCol column
            int maxRow = 0;
            for (int i = 0; i < n; i++) {
                if (mat[i][midCol] > mat[maxRow][midCol]) {
                    maxRow = i;
                }
            }
            
            // Step 2: Check left and right neighbors safely
            boolean leftIsBig = (midCol - 1 >= 0) && (mat[maxRow][midCol - 1] > mat[maxRow][midCol]);
            boolean rightIsBig = (midCol + 1 < m) && (mat[maxRow][midCol + 1] > mat[maxRow][midCol]);
            
            // Step 3: If neither is bigger, it's a peak!
            if (!leftIsBig && !rightIsBig) {
                return new int[] { maxRow, midCol };
            } 
            // If the left neighbor is larger, move search space to the left
            else if (leftIsBig) {
                high = midCol - 1;
            } 
            // Otherwise, move search space to the right
            else {
                low = midCol + 1;
            }
        }
        
        return new int[] { -1, -1 };
    }
}