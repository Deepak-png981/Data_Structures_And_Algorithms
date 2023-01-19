//{ Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node* inputList(int size)
{
    Node *head, *tail;
    int val;
    
    cin>>val;
    head = tail = new Node(val);
    
    while(--size)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
}

Node* findIntersection(Node* head1, Node* head2);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>> n >> m;
	    
	    Node* head1 = inputList(n);
	    Node* head2 = inputList(m);
	    
	    Node* result = findIntersection(head1, head2);
	    
	    printList(result);
	    cout<< endl;
	}
	return 0;
}

// } Driver Code Ends


/* The structure of the Linked list Node is as follows:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/
// 3 4
// 1 2 2
// 2 2 3 4

// 5 4
// 1 2 3 4 6
// 2 4 6 8

Node* findIntersection(Node* head1, Node* head2)
{
    map<int , int> mp;
    Node* temp = head1;
    while(temp){
        mp[temp->data]++;
        temp = temp->next;
    }
    temp = head2;
    while(temp){
        mp[temp->data]++;
        temp = temp->next;
    }
    Node* dummyhead;
    Node* head;
    dummyhead = head = new Node(-1);
    for(auto it : mp){
        if(it.second > 1){
            for(int i = 1; i<=it.second/2; i++){
                Node* newnode = new Node(it.first);
                dummyhead -> next = newnode;
                dummyhead = dummyhead->next;
            }
        }
    }
    return head->next;
}