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
    ListNode* getMiddle(ListNode* head) {
        if(head==NULL || head->next == NULL) return NULL;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL || head->next == NULL) return NULL;
        ListNode* middle = getMiddle(head);
        ListNode* nextNode = middle->next;
        middle->next = nextNode->next;
        delete nextNode;
        return head;
    }
};