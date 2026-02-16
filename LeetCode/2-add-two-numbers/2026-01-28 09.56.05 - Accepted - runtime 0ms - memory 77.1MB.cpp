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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyNode=new ListNode(0);
        ListNode* curr=dummyNode;
        int carry=0;
        while(l1!=nullptr && l2!=nullptr){
            int sum=l1->val+l2->val;
            sum+=carry;
            carry=sum/10;
            sum%=10;
            curr->next=new ListNode(sum);
            curr=curr->next;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1!=nullptr){
            int currL1=l1->val;
            currL1+=carry;
            carry=currL1/10;
            currL1%=10;
            curr->next=new ListNode(currL1);
            curr=curr->next;
            l1=l1->next;
        }
        while(l2!=nullptr){
            int currL2=l2->val;
            currL2+=carry;
            carry=currL2/10;
            currL2%=10;
            curr->next=new ListNode(currL2);
            curr=curr->next;
            
            l2=l2->next;
        }
        if(carry) curr->next=new ListNode(carry);
        return dummyNode->next;
    }
};