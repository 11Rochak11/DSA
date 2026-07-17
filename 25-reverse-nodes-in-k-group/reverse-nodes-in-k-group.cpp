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
    ListNode* findkth(ListNode* temp, int k) {
        k--;
        while (temp != NULL && k > 0) {
            temp = temp->next;
            k--;
        }
        return temp;
    }

    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr != NULL) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prev = NULL;

        while (temp != NULL) {

            // Find kth node
            ListNode* kth = findkth(temp, k);

            // Less than k nodes left
            if (kth == NULL) {
                if (prev != NULL)
                    prev->next = temp;
                break;
            }

            // Save next group's starting node
            ListNode* nextGroup = kth->next;

            // Disconnect current group
            kth->next = NULL;

            // Reverse current group
            ListNode* newHead = reverse(temp);

            // Connect previous group
            if (temp == head) {
                head = newHead;
            } else {
                prev->next = newHead;
            }

            // 'temp' is now the last node of reversed group
            prev = temp;

            // Move to next group
            temp = nextGroup;
        }

        return head;
    }
};