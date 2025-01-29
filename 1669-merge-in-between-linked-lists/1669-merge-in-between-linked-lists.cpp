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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* head = list1, *curr = list1;
        for(int i = 0; i < a-1; i++) curr = curr->next;

        ListNode* b4remove = curr;
        ListNode* fremove = curr->next;

        for(int i = a-1; i < b; i++) {
            ListNode* temp = fremove;
            fremove = fremove->next;
            delete temp;
        }
        b4remove->next = list2;
        while(curr->next) curr = curr->next;

        curr->next = fremove;

        return head;
    }
};