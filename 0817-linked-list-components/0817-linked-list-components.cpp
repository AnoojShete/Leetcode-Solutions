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
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int res = 0;
        while(head) {
            if(st.count(head->val) && (head->next == nullptr || !st.count(head->next->val)))
                res++;
            head = head->next;
        }

        return res;
    }
};