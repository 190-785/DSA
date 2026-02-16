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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return true;
        ListNode* slowptr = head;
        ListNode* fastptr = head;
        while (fastptr != nullptr && fastptr->next != nullptr) {
            //cout << slowptr->val;
            slowptr = slowptr->next;
            fastptr = fastptr->next->next;
        }
        ListNode* midptr = reverseList(slowptr);
        ListNode* dummy = head;
        while (midptr != nullptr) {
            if (dummy->val != midptr->val)
                return false;
            dummy = dummy->next;
            midptr = midptr->next;
        }
        return true;
    }
};