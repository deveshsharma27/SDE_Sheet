/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt = 0;
        ListNode* temp = head;
        while (temp) {
            cnt++;
            temp = temp->next;
        }

        int size = cnt - n;

        if(size==0){
            return head->next; // target index is head then remove the head;
        }

        ListNode* p1 = head;
        while (size >1) { // size > 1 beacause p1 land on the  right node  which i wnat to delete 
            p1 = p1->next;
            size--;
        }
        if (p1->next) {

            p1->next = p1->next->next;
        }

        return head;
    }
};