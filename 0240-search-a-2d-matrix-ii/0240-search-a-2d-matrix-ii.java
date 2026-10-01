class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        
        int n = matrix.length; //row
        int m = matrix[0].length;//col

        int row = 0 , col= m-1;

        while(row<n && col>=0){
            
            if(matrix[row][col]==target){
                return  true;
            }

            if(matrix[row][col] < target){
                row++;
            }else{
                col--;
            }
        }

        return false;
    }
}