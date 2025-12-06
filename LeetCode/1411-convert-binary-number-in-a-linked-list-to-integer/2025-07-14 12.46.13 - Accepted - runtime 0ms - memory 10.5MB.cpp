class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int res = 0;
        ListNode* temp = head;
        while (temp != nullptr) {
            res = res * 2 + temp->val;
            temp = temp->next;
        }
        return res;
    }
};
