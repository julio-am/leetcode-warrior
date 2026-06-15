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
        l1 = reverseNumber(l1);
        l2 = reverseNumber(l2);

        ListNode* begin = new ListNode();
        ListNode* cur = begin;
        int carry = 0;

        // Loop while any value still remains to be added 
        while (l1 || l2 || carry) {
            int l = l1 ? l1->val : 0;
            int r = l2 ? l2->val : 0;

            int sum = l + r + carry;
            cur->next = new ListNode(sum % 10);
            carry = sum / 10;

            cur = cur->next;
            l1 = l1 ? l1->next : NULL;
            l2 = l2 ? l2->next : NULL;
        }

        // Safely remove the first node, which is just 0. 
        ListNode* result = begin->next;
        delete begin;
        return reverseNumber(result);
    }

    ListNode* reverseNumber(ListNode* l1) {
        ListNode *curr = l1, *prev = nullptr, *next;

        while (curr) {
            // store next
            next = curr->next;

            // set new current next to previous 
            curr->next = prev;

            // move the current pointers
            prev = curr;
            curr = next;
        }

        return prev;
    }
};
