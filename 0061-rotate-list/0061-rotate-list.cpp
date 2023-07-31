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
        if(head == NULL or head -> next == NULL or k == 0)
            return head;
        ListNode* temp = head;
        int size = 1;
        while(temp -> next != NULL){
            temp = temp->next;
            size++;
        }
        temp -> next = head;
        k = k%size;
        k = size - k;
        while(k--){
            temp = temp->next;
            
        }
        head = temp->next;
        temp->next = NULL;
        return head;
    }
};