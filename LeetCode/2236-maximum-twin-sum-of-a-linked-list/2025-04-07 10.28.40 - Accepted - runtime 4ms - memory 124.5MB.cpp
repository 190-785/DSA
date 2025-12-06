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
    ListNode* findMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast->next != nullptr) {
            return slow->next;
        }
        return slow;
    }
    ListNode* reverse(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = nullptr;
        while (temp != nullptr) {
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }
    int pairSum(ListNode* head) {
        ListNode* mid = findMid(head);
        ListNode* rev = reverse(mid);
        int maxS = 0;
        ListNode* part1 = head;
        ListNode* part2 = rev;
        while (part1 != rev && part2 != nullptr) {
            int sum = part1->val + part2->val;
            maxS = max(maxS, sum);
            part1 = part1->next;
            part2 = part2->next;
        }
        return maxS;
    }
};