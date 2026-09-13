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
    private static ListNode reverseList(ListNode head) {
        ListNode prev = null;
        ListNode cur = head;

        while (cur != null) {
            ListNode temp = cur.next;

            cur.next = prev;

            prev = cur;
            cur = temp;
        }
        return prev;
    }

    public boolean isPalindrome(ListNode head) {
        if (head == null || head.next == null)
            return true;

        ListNode slow = head;
        ListNode fast = head;

        // find midddle Node 
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }

        //Middle node is slow -
        //reverse second half
        ListNode newHead = reverseList(slow);
        ListNode firstHalf = head;

        ListNode p1 = firstHalf;
        ListNode p2 = newHead;
        boolean result = true;
        while (p2 != null) {
            if (p1.val != p2.val) {
                result = false;
                break;
            }

            p1 = p1.next;
            p2 = p2.next;

        }
        reverseList(newHead);
        return result;

        //----------------------------------------------------------------------

        //     ListNode temp = head;

        //     List<Integer>arr = new ArrayList<>();

        //     while(temp!=null){
        //         arr.add(temp.val);
        //         temp = temp.next;
        //     }

        //     int n = arr.size();
        //      int left =0 , right = n-1;

        //      while(left<right){
        //         if(arr.get(left)!=arr.get(right)){
        //             return false;
        //         }
        //         left++;
        //         right--;
        //      }
        //    return true;
    }
}