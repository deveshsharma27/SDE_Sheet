class Solution {
    public List<List<Integer>> minimumAbsDifference(int[] arr) {
        Arrays.sort(arr);

        List<List<Integer>> ans = new ArrayList<>();
         int minDiff = Integer.MAX_VALUE;

        for(int i=0; i<arr.length-1; i++){
            

            int curDiff = arr[i+1]-arr[i];

            if(curDiff < minDiff){
                minDiff = curDiff;
                ans.clear();
                ans.add(Arrays.asList(arr[i], arr[i+1]));
            }
           else if(curDiff== minDiff){
                ans.add(Arrays.asList(arr[i],arr[i+1]));
            }
        }
        return ans;
    }
}