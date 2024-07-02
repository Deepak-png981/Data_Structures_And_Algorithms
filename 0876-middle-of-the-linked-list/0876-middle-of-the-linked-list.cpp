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
private:
    int calSize(ListNode* head){
        int count = 0;
        while(head != NULL){
            count++;
            head = head->next;
        }
        return count;
    }
public:
    ListNode* middleNode(ListNode* head) {
        int size = calSize(head);
        ListNode* temp = head;
        int count = (size/2)+1;
        ListNode* curr = head;
        while(curr != NULL){
            count = count - 1;
            if(count == 0)
                break;
            curr = curr->next;
        }
        return curr;
    }
};