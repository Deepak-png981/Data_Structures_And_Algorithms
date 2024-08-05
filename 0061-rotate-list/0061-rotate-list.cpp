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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL or head -> next == NULL)    return head;
        int count = 1;
        ListNode* temp = head;
        while(temp -> next != NULL){
            ++count;
            temp = temp -> next;
        }
        k = k % count;
        temp -> next = head;
        int end = count - k;
        while(end--)
            temp = temp->next;
        ListNode* newHead = temp->next;
        temp->next = NULL;
        return newHead;
    }
};