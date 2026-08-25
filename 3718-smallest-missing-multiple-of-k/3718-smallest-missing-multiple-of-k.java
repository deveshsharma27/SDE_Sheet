class Solution {
    public int missingMultiple(int[] nums, int k) {
      Set<Integer> s = new HashSet<>();
      for(int num : nums){
        s.add(num);
      }  

      int ans = k;

      while(s.contains(ans)){
        ans+=k;
      }
      return ans;
    }
}