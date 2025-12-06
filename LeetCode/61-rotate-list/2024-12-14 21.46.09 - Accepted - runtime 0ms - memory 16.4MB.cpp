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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr || head->next==nullptr) return head;
        int count = 1;
        ListNode* current = head;
        while (current->next != nullptr) {
            count++;
            current = current->next;
        }
        current->next = head;
        k = k % count;
        k = count - k;
        while (k) {
            current = current->next;
            k--;
        }
        ListNode* temp = current->next;
        current->next = nullptr;
        head = temp;
        return head;
    }
};