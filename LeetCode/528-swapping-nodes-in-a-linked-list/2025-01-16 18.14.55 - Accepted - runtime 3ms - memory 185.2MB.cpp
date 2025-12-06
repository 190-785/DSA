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
    ListNode* swapNodes(ListNode* head, int k) {
        if(head==nullptr || head->next==nullptr) return head;
        ListNode* slow=head;
        ListNode* fast=head;
        for (int i = 0; i < k-1; ++i) {
            fast = fast->next;
        }
        ListNode* knode=fast;
        fast=fast->next;
        while (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
        swap(knode->val,slow->val);
        return head;
    }
};