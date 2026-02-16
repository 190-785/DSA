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
    bool hasCycle(ListNode *head) {
        ListNode* slowptr=head;
        ListNode* fastptr=head->next;
        while(fastptr!=nullptr && fastptr->next!=nullptr){
            if(slowptr==fastptr) return true;
            slowptr=slowptr->next;
            fastptr=fastptr->next->next;
        }   
        return false;
    }
};