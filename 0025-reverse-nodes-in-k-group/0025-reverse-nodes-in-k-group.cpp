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
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr != NULL){
            ListNode* front = curr->next;
            curr -> next = prev;
            prev = curr;
            curr = front;
        }
        return prev;
    }
    ListNode* getKthNode(ListNode* head , int k){
        k--;
        while(head != NULL and k > 0){
            k--;
            head = head->next;
        }
        return head;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevLast = NULL;
        while(temp != NULL){
            ListNode* kthNode = getKthNode(temp , k);
            if(kthNode == NULL){
                if(prevLast != NULL){
                    prevLast -> next = temp;
                }
                break;
            }
            ListNode* nextNode = kthNode -> next;
            kthNode -> next = NULL;
            reverse(temp);
            if(temp == head){
                head = kthNode;
            }else{
                prevLast -> next = kthNode;
            }
            prevLast = temp;
            temp = nextNode;
        }
        return head;
    }
};