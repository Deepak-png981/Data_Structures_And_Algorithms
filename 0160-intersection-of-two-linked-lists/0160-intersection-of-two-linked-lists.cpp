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
        int len1 = 0 , len2 = 0;
        ListNode*temp1 = headA;
        ListNode*temp2 = headB;
        while(temp1!=NULL or temp2 != NULL){
            if(temp1 != NULL){
                len1++;
                temp1=temp1->next;
            }
            if(temp2 != NULL){
                len2++;
                temp2=temp2->next;
            }
        }
        int diff = len1-len2;
        if(diff < 0){
            while(diff++ != 0){
                headB = headB->next;
            }
        }else{
            while(diff-- != 0){
                headA = headA->next;
            }
        }
        while(headA != NULL){
            if(headA == headB){
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};