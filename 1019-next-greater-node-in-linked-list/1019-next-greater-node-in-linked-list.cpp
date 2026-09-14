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
    ListNode* rev(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* node = rev(head->next);
        head->next->next = head;
        head->next = nullptr;
        return node;
    }
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        ListNode* curr = rev(head);
        stack<int> st;
        while(curr) {
            while(!st.empty() && st.top() <= curr->val) st.pop();
            ans.push_back(st.empty() ? 0 : st.top());
            st.push(curr->val);
            curr = curr->next;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};