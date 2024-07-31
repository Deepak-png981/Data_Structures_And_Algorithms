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
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode* , int>mp;
        ListNode* temp = head;
        while(temp != NULL){
            if(mp[temp] == 1)
                return temp;
            mp[temp] = 1;
            temp = temp->next;
        }
        return NULL;
    }
};