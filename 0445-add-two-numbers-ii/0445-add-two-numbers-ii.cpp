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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> st1, st2;
        while(l1) {
            st1.push(l1->val);
            l1 = l1->next;
        }
        while(l2) {
            st2.push(l2->val);
            l2 = l2->next;
        }
        int sum = 0;
        ListNode* node = new ListNode(0);
        while(!st1.empty() || !st2.empty()) {
            if(!st1.empty()) {
                sum += st1.top();
                st1.pop();
            }
            if(!st2.empty()) {
                sum += st2.top();
                st2.pop();
            }
            node->val = sum % 10;
            ListNode* head = new ListNode(sum / 10);
            head->next = node;
            node = head;
            sum /= 10;
        }

        return node->val == 0 ? node->next : node;
    }
};