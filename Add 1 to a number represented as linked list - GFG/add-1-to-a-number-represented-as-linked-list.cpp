//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    private:
    Node* reverseLL(Node * head){
        if(!head or !head->next)
            return head;
        Node* prev = NULL;
        Node* curr = head;
        Node* temp;
        while(curr != NULL){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    public:
    Node* addOne(Node *head) 
    {
        
        
        head = reverseLL(head);
        Node* curr = head;
        bool addDone = false;
        while(curr != NULL and addDone == false){
            //first case hai 999 ka so simply last 9 ka , ushko 1 kerdo or end mein
            //0 add ker rha hoon
            if(curr -> next == NULL and curr->data == 9){
                curr->data = 1;
                Node* newnode = new Node(0);
                newnode ->next = head;
                head = newnode;
                curr = curr->next;
            }
            //matr value 9 hai to ushe zero kerdo bus
            else if(curr->data == 9){ 
                curr->data = 0;
                curr = curr ->next;
            }else{
                curr->data = curr->data + 1;
                curr = curr->next;
                addDone = true;
            }
            
        }
        return reverseLL(head);
        
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends