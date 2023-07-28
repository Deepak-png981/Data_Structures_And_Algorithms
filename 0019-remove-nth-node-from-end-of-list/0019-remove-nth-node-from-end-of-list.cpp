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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int count = 0;
        while(temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        ListNode* dummyNode = new ListNode(-1);
        dummyNode->next = head;
        temp = dummyNode;
        count = count-n;
        while(count != 0){
            count--;
            temp = temp->next;            
        }
        temp->next = temp -> next ->next;
        return dummyNode->next;
    }
};