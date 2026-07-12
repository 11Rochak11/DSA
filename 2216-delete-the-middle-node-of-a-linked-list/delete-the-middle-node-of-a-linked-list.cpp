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
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return NULL;
        }
        ListNode* tort=head;
        ListNode* hare=head;
        hare=hare->next->next;
        while(hare!=NULL && hare->next!=NULL){
            tort=tort->next;
            hare=hare->next->next;
        }
        ListNode* front = tort->next;
        tort->next=front->next;
        delete front;
        return head;
    }
};