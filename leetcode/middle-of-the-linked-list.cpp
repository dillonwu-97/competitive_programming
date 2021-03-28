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
    ListNode* middleNode(ListNode* head) {
        ListNode* temp = head;
        int n = 0;
        while (temp->next != NULL) {
            n += 1;
            temp = temp->next;
        }
        n = round(n /2.0);
        temp = head;
        for (int i = 0; i < n; i++) {
            temp = temp->next;
        }
        return temp;
    }
};