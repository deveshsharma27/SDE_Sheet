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
    ListNode* findKthNode(ListNode* temp, int k){
    if(!temp) return temp;
    ListNode* kNode=temp;
    while(kNode && k>1){
     k--;
     kNode=kNode->next;

    }
    return kNode;

}
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL ) return head;
        ListNode* newHead=reverseList(head->next);
        ListNode* front=head->next;
        front->next=head;
        head->next=NULL;

        return newHead;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k==1) return head;

        ListNode* temp = head;
        ListNode *prevNode=NULL;
        ListNode* nextNode;

        while (temp) {
            ListNode* kthNode = findKthNode(temp, k);
            if (kthNode == NULL) {
            if (prevNode) prevNode->next = temp;
                break;
            }

            ListNode* nextNode = kthNode->next;
            kthNode->next = NULL;
             ListNode* kthHead= reverseList(temp);

            if (temp == head) head = kthHead;
               
            else prevNode->next = kthHead;
            prevNode = temp;

            temp->next = nextNode;
               temp=nextNode;
        }
     
        return head;
        
    }
};