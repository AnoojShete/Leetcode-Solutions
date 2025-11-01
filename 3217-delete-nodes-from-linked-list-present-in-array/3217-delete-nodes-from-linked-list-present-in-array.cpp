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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st(nums.begin(), nums.end());
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;
        ListNode* temp = head;
        while(temp) {
            if(st.count(temp->val)) {
                prev->next = temp->next;
            }
            else prev = temp;

            temp = temp->next;
        }

        return dummy->next;
    }
};