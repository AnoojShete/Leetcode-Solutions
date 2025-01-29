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
    int twiceOfvalue(ListNode* head) {
        if(!head) return 0;
        int doubleVal = head->val * 2 + twiceOfvalue(head->next);
        head->val = doubleVal % 10;
        
        return doubleVal / 10;
    } 
    ListNode* doubleIt(ListNode* head) {
        int carry = twiceOfvalue(head);
        if(carry) {
            head = new ListNode(carry, head);
        }
        return head;
    }
};