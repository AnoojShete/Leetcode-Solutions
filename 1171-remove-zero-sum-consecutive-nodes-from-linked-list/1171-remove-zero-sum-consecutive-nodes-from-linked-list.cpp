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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        int preSum = 0;
        map<int, ListNode*> mpp;
        mpp[preSum] = dummy;
        ListNode* temp = head;
        while(temp) {
            preSum += temp->val;
            if(mpp.find(preSum) != mpp.end()) {
                ListNode* to_delete = mpp[preSum]->next;
                int temp_sum = preSum + to_delete->val;
                while(to_delete != temp) {
                    to_delete = to_delete->next;
                    temp_sum += to_delete->val;
                }
                mpp[preSum]->next = temp->next;
            }
            else mpp[preSum] = temp;

            temp = temp->next;
        }
        return dummy->next;
    }
};