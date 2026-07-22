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
    void reorderList(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next&&fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode*curr=slow->next;
        slow->next=NULL;
        ListNode*prev=NULL;
        while(curr){
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        ListNode*dummy=new ListNode(-1);
        ListNode*temp=dummy;
        ListNode*temp2=head;
        while(temp2&&prev){
            temp->next=temp2;
            temp=temp->next;
            temp2=temp2->next;
            temp->next=prev;
            temp=temp->next;
            prev=prev->next;
        }
        while(temp2){
            temp->next=temp2;
            temp=temp->next;
            temp2=temp2->next;
        }
    }
};
