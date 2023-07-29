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
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* next = NULL;
        while(head != NULL){
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL or head -> next == NULL)
            return true;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next!=NULL&&fast->next->next!=NULL){
            slow = slow->next;
            
            fast = fast->next->next;
            
        }
        slow -> next = reverse(slow->next);
        slow = slow->next;
        
        // ListNode* dummynode = head;
        while(slow != NULL){
            if(slow ->val  != head -> val)
                return false;
            head = head -> next;
            slow = slow -> next;
        }
        return true;
        
    }
};