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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* kth = head, *nkth = head;
        for(int i = 0; i < k-1; i++) {
            nkth = nkth->next;
        }
        ListNode* right = nkth;
        while(nkth->next) {
            kth = kth->next;
            nkth = nkth->next;
        }

        swap(right->val, kth->val);

        return head;
    }
};