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
    int gcd(int a, int b) {
        if(a == 0) return b;
        if(b == 0) return a;
        if(a == b) return a;

        return gcd(b % a, a);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head || !head) return head;
        ListNode* temp = head;
        ListNode* nxt = head->next;
        while(temp && nxt) {
            ListNode* gcdNode = new ListNode(gcd(temp->val, nxt->val), nxt);
            temp->next = gcdNode;
            temp = nxt;
            nxt = nxt->next;
        }

        return head;
    }
};