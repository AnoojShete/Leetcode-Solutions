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
    int length(ListNode* head) {
        int len = 0;
        while(head) {
            len++;
            head = head->next;
        }
        return len;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int size = length(head);
        int part_size = (size / k);
        int larger_part = (size % k);
        vector<ListNode*> ans(k);
        ListNode* cur = head;
        for(int i = 0; i < k; i++) {
            int subListSize = (i < larger_part) ? part_size + 1 : part_size;
            if(subListSize == 0) {
                ans[i] = nullptr;
            }
            else {
                ListNode* subListHead = cur;
                for(int j = 0; j < subListSize - 1; j++) {
                    cur = cur->next;
                }
                ListNode* nextNode = cur->next;
                cur->next = nullptr;
                ans[i] = subListHead;
                cur = nextNode;
            }
        }
        return ans;
    }
};