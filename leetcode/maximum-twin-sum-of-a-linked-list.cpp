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
    int pairSum(ListNode* head) {
        vector<int> v;
        while (head != NULL) {
            v.push_back(head->val);
            head = head->next;
        }
        int m = -1;
        for (int i = 0; i < v.size(); i++) {
            if (v[i] + v[ v.size() - 1 - i] > m) {
                m = v[i] + v[ v.size() - 1 - i];
            }
        }
        return m;
            }
};