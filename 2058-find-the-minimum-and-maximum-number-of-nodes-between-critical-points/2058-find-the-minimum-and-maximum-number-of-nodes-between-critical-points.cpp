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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* temp = head;
        vector<int> arr;

        while (temp) {
            arr.push_back(temp->val);
            temp = temp->next;
        }

        vector<int> critical;
        for (int i = 1; i < arr.size() - 1; i++) {
            if ( arr[i] > arr[i-1] && arr[i] > arr[i + 1] ||
                arr[i] < arr[i-1] && arr[i] < arr[i + 1]) {
                critical.push_back(i);
            }
        }

        if (critical.size() < 2) {
            return {-1, -1};
        }

        int minDist = 1e9;

        for (int i = 1; i < critical.size(); i++) {
            minDist = min(minDist, critical[i] - critical[i - 1]);
        }

        int maxDist = critical.back() - critical.front();

        return {minDist, maxDist};
    }
};