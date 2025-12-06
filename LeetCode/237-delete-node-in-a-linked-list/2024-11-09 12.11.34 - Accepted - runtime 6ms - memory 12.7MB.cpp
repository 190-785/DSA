/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        int vl=node->next->val;
        ListNode *temp=node;
        temp->next=temp->next->next;
        temp->val=vl;
    }
};