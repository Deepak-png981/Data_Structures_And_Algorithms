/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
private:
    void insertAtTail(Node* &head , Node* &tail , int d){
        Node* newnode = new Node(d);
        if(head == NULL){
            head = newnode;
            tail = newnode;
            return;
        }else{
            tail -> next = newnode;
            tail = tail->next;
            return;
        }
    }
public:
    Node* copyRandomList(Node* head) {
        // step 1: insert into the clonenode
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        Node* temp = head;
        while(temp != NULL)
        {
            insertAtTail(cloneHead , cloneTail , temp->val);
            temp = temp -> next;
        }
        //step 2 : creating a map
        unordered_map<Node* , Node*>mp;
        temp = head;
        Node* temp2 = cloneHead;
        while(temp != NULL){
            mp[temp] = temp2;
            temp = temp->next;
            temp2 = temp2->next;
        }
        //step3 : handling the random variable
        temp = head;
        temp2 = cloneHead;
        while(temp != NULL){
            temp2->random = mp[temp->random];
            temp = temp->next;
            temp2 = temp2->next;
        }
        return cloneHead;
    }
    
    
    
    
    
    
    
    
    
    
    
    
};