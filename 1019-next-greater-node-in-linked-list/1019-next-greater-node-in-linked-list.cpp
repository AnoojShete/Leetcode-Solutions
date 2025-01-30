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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans, st;
        for(ListNode* node = head; node; node = node->next) {
            // Creating a decreasing order stack -> monotonic stack
            while(st.size() && ans[st.back()] < node->val) {
                ans[st.back()] = node->val;
                st.pop_back();
            }
            st.push_back(ans.size());
            ans.push_back(node->val);
        }
        for(int i : st) ans[i] = 0;
        return ans;
    }
};