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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp=head;
        if(head==NULL||head->next==NULL){
            return head;
        }
        while (temp!=NULL&&temp->next!=NULL){
            ListNode* front=temp->next;
            if(temp->val==front->val){
                temp->next=front->next;
                delete front;
            }
            else{
                temp=temp->next;
            }
        }
        return head;
        
    }
};