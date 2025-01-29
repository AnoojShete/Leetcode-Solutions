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
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> st;
        ListNode* cur = head;
        while(cur) {
            while(!st.empty() && st.top()->val < cur->val) st.pop();
            st.push(cur);
            cur = cur->next;
        }
        ListNode* next = nullptr;
        while(!st.empty()) {
            cur = st.top();
            st.pop();
            cur->next = next;
            next = cur;
        }
        return cur;
    }
};