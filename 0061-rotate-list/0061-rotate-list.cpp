class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k == 0) return head;
        int len = 0;
        for(auto node = head; node != nullptr; node = node->next) {len++;}
        k %= len;
        if(k == 0) return head;
        ListNode *fast = head, *slow = head;
        while(k--) {
            fast = fast->next;
        }
        while(fast->next != nullptr) fast = fast->next, slow = slow->next;
        fast->next = head;
        ListNode* newHead = slow->next;
        slow->next = nullptr;
        return newHead;
    }
};