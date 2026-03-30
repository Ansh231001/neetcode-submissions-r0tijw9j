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
        int carry = 0;
        ListNode* h1 = l1;
        ListNode* h2 = l2;
        ListNode* fh = new ListNode(-1);
        ListNode* cur = fh;

        while (h1 != nullptr || h2 != nullptr || carry != 0) {
            int a = (h1 != nullptr) ? h1->val : 0;
            int b = (h2 != nullptr) ? h2->val : 0;

            int sum = a + b + carry;
            carry = sum / 10;
            int value = sum % 10;

            cur->next = new ListNode(value);
            cur = cur->next;

            if (h1) h1 = h1->next;
            if (h2) h2 = h2->next;
        }

        ListNode* res = fh->next;
        delete fh; // optional: clean up dummy head
        return res;
    }
};