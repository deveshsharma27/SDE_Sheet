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
    public int[] nodesBetweenCriticalPoints(ListNode head) {
        ListNode prev = head;
        ListNode cur = head.next;
        ListNode next = head.next.next;

        int firstCritical=-1 , lastCritical=-1;
        int index=1;
        int minDist=Integer.MAX_VALUE;

        while(next!=null){
             
             if(cur.val > prev.val && cur.val > next.val 
                || cur.val < prev.val && cur.val < next.val){
                
                if(firstCritical== -1){
                    firstCritical = index;
                }else{ //index=2
                     minDist = Math.min(minDist , Math.abs(index-lastCritical));
                }
                lastCritical=index;
             }
             prev = cur;
             cur = next;
             next = next.next;
             index++;
        }

        if(lastCritical==firstCritical){
            return new int [] {-1, -1};
        }

        int maxDist= Math.abs(firstCritical-lastCritical);

        return new int[] {minDist , maxDist};
    }

}