/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public boolean isPalindrome(ListNode head) {
        ListNode temp = head;

        List<Integer>arr = new ArrayList<>();

        while(temp!=null){
            arr.add(temp.val);
            temp = temp.next;
        }

        int n = arr.size();
         int left =0 , right = n-1;

         while(left<right){
            if(arr.get(left)!=arr.get(right)){
                return false;
            }
            left++;
            right--;
         }
       return true;
    }
}