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
        ListNode* slowptr = head;
        ListNode* fastptr = head->next;
        while (fastptr != nullptr && fastptr->next != nullptr) {
            slowptr = slowptr->next;
            fastptr = fastptr->next->next;
        }
        return slowptr;
    }
    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                temp->next = list1;
                temp = list1;
                list1 = list1->next;
            } else {
                temp->next = list2;
                temp = list2;
                list2 = list2->next;
            }
        }
        if (list1)
            temp->next = list1;
        if (list2)
            temp->next = list2;
        return dummyNode->next;
    }

    ListNode* mergeSort(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode* mid = findMid(head);
        ListNode* leftHead = head;
        ListNode* rightHead = mid->next;
        mid->next = nullptr;
        leftHead = mergeSort(leftHead);
        rightHead = mergeSort(rightHead);
        return merge(leftHead, rightHead);
    }
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        return mergeSort(head);
    }
};