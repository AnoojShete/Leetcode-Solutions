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
    ListNode* reverse(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* newHead = reverse(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = nullptr;

        return newHead;
    }

    ListNode* getMiddle(ListNode* head) {
        ListNode* slow = head, *fast = head;
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    int pairSum(ListNode* head) {
        int maxi = 0;
        ListNode* middle = getMiddle(head);
        ListNode* first = head;
        ListNode* second = reverse(middle->next);
        while(second) {
            int sum = first->val + second->val;
            if(sum > maxi) maxi = sum;
            first = first->next;
            second = second->next;
        }

        return maxi;
    }
};