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
    ListNode* middleNode(ListNode* head) {
        if (head == NULL) {
            return head;
        }
        ListNode* slowptr = head;
        ListNode* fastptr = head;
        while (fastptr->next != NULL && fastptr->next->next != NULL) {
            slowptr = slowptr->next;
            fastptr = fastptr->next->next;
        }
        if (fastptr->next != NULL) {
            return slowptr->next;
        }
        return slowptr;
    }
};