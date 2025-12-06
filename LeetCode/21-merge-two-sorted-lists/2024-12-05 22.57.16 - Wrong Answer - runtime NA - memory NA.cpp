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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr)
            return list2;
        if (list2 == nullptr)
            return list1;
        if (list1->val > list2->val)
            return mergeTwoLists(list2, list1);

        ListNode* temp1 = list1;
        ListNode* temp2 = list2;

        while (temp1 != nullptr && temp2 != nullptr) {
            if (temp1->val <= temp2->val) {
                ListNode* cur = temp1->next;
                temp1->next = temp2;
                temp1 = cur;
            } else {
                ListNode* cur = temp2->next;
                temp2->next = temp1;
                temp2 = cur;
            }
        }

        return list1;
    }
};
