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
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        // create a priority quee with a custom comparator
        auto cmp = [](ListNode* l, ListNode* r) { return l->val > r->val; }
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq;

        // Add first element of each list to priority queue
        for (auto list : lists) {
            if (list) pq.push(list);
        }

        // put first element on list and insert next one into queue
        ListNode* head = new ListNode(0);
        ListNode* tail = head;
        while (!pq.empty()) {
            tail->next = pq.top();
            tail = tail->next;
            pq.pop();

            if (tail->next) pq.push(tail->next);
        }

        return head->next;
    }
};
