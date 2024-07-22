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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        while(headB != NULL){
            ListNode* temp = headA;
            while(temp != NULL){
                if(temp == headB)
                    return temp;
                temp = temp->next;
            }
            headB = headB->next;
        }
        return NULL;
    }
};