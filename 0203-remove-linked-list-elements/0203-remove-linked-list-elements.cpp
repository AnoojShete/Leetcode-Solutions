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
    ListNode* removeElements(ListNode* head, int val) {

        if(head && head->val == val) {
            while(head && head->val == val) head = head->next;
        }
        if(!head || !head->next) return head;

        ListNode* temp = head->next;
        ListNode* prev = head;
        while(temp) {
            if(temp->val == val) {
                if(temp->next) {
                    temp = temp->next;
                    prev->next = temp;
                }
                else {
                    prev->next = nullptr;
                    temp = nullptr;
                }
            }
            else {
                prev = temp;
                temp = temp->next;
            }
        }
        return head;
    }
};