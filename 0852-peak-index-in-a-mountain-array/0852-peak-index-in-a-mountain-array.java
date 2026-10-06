class Solution {
    public int peakIndexInMountainArray(int[] arr) {

        int n = arr.length;
// The peak cannot be at the edges, so start searching from 1 to n-2
        int low = 1, high = n - 2;

        while (low < high) {

            int mid = (low + high) / 2;
        
            if (arr[mid] < arr[mid + 1]) {
                low = mid+1;
            } else {
                high = mid;
            }

        }
        return low;
    }
}