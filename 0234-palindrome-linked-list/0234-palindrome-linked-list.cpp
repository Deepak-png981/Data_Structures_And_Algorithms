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
    ListNode* reverseLinkedList(ListNode* head){
        ListNode* prev = NULL;
        ListNode* temp = head;
        while(temp != NULL){
            ListNode* nextNode = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nextNode;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast->next != NULL and fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* newHead = reverseLinkedList(slow->next);
    while(newHead != NULL){
        if(head->val != newHead->val)
            return false;
        head = head->next;
        newHead = newHead -> next;
    }
        return true;
    }
};