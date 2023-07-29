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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int size = 0;
        ListNode* temp = head;

        while(temp!=NULL){
            temp = temp -> next;
            size++;
        }
        if(size < k)return head;
        //base case
        if(head == NULL)
            return NULL;
        
        //step 1:
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        int count = 0;
        while(curr != NULL and count < k){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        //step 2 :call the recursion
        if(next != NULL){
            head -> next = reverseKGroup(next , k);
        }
        return prev;
    }
};