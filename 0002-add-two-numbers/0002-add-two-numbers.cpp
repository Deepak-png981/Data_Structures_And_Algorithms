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
// 15
// carry = 15 / 10;
// sum = 15 % 10;
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* result = dummy;
        int carry = 0;
        while((l1 != NULL or l2 != NULL ) or carry){
            int sum = 0;
            if(l1 != NULL){
                sum += l1 -> val;
                l1 = l1 -> next;
            }
            if(l2 != NULL){
                sum += l2->val;
                l2 = l2 -> next;
            }
            sum += carry;
            carry = sum / 10;
            ListNode* temp = new ListNode(sum % 10);
            result -> next = temp;
            result = result->next;
        }
        return dummy->next;
    }
};