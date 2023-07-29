/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
        while(head1 != NULL){
            ListNode* temp = head2;
            while(temp != NULL){
                if(head1 == temp)
                    return head1;
                temp = temp->next;
            }
            head1 = head1 -> next;
        }
        return NULL;
    }
};