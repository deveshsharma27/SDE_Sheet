class Solution {
    public List<Integer> majorityElement(int[] nums) {
         
        int n = nums.length;

        HashMap<Integer, Integer>mpp = new HashMap<>();

        for(int num: nums){
            mpp.put(num , mpp.getOrDefault(num , 0)+1);
        }
        List<Integer>res = new ArrayList<>();

        for(int num : mpp.keySet()){

            if(mpp.get(num) > n/3){
              res.add(num);
            }
        }
      return res;
      
    }
}