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
    bool isPalindrome(ListNode* head) {
        ListNode* fast=head;
        ListNode* slow= head;
        if(head==NULL||head->next==NULL){
            return true;
        }
        while(fast->next!=NULL && fast->next->next!=NULL ){
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode* temp=slow->next;
        ListNode* prev=NULL;

        while(temp){
           ListNode* front= temp->next;
           temp->next=prev;
           prev=temp;
           temp=front;

        }
        slow->next=NULL;
        temp= head;
        while(prev!=NULL&& temp!=NULL){
            if(prev->val!=temp->val){
                return false;
            }
            else{
                prev=prev->next;
                temp=temp->next;
            }

        }
        return true;


       
        
    }
};