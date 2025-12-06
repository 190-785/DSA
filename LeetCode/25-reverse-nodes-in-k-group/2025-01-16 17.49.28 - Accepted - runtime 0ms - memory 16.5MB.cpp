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
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode* newHead = reverseList(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = nullptr;
        return newHead;
    }

    ListNode* getKthNode(ListNode* temp, int k) {
        k -= 1;
        while (temp != nullptr && k > 0) {
            k--;
            temp = temp->next;
        }
        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevLast = nullptr;

        while (temp != nullptr) {
            ListNode* kThNode = getKthNode(temp, k);
            if (kThNode == nullptr) {
                if (prevLast) {
                    prevLast->next = temp;
                }
                break;
            }

            ListNode* nextNode = kThNode->next;
            kThNode->next = nullptr;
            reverseList(temp);

            if (temp == head) {
                head = kThNode;
            } else {
                prevLast->next = kThNode;
            }

            prevLast = temp;
            temp = nextNode;
        }

        return head;
    }
};
