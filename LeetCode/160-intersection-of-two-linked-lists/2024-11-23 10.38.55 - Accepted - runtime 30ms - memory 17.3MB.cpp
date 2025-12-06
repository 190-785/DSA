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
    int count(ListNode* head) {
        int count = 0;
        ListNode* temp = head;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    ListNode* intersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* tempA = headA;
        ListNode* tempB = headB;
        while (tempA != NULL) {
            if (tempA == tempB)
                return tempA;
            tempA = tempA->next;
            tempB = tempB->next;
        }
        return NULL;
    }

    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if (headA == NULL || headB == NULL)
            return NULL;
        int countA = count(headA);
        int countB = count(headB);
        int diff = countA - countB;
        if (!diff) {
            return intersectionNode(headA, headB);
        } else if (diff > 0) {
            ListNode* temp = headA;
            while (diff) {
                temp = temp->next;
                diff--;
            }
            return intersectionNode(temp, headB);
        } else {
            ListNode* temp = headB;
            while (diff < 0) {
                temp = temp->next;
                diff++;
            }
            return intersectionNode(headA, temp);
        }
        return NULL;
    }
};