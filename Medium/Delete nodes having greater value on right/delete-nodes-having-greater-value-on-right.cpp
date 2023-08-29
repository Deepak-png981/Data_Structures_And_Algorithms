//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
     Node* dummy=new Node(0);
    Node* ans=dummy;
    Node* reverse(Node* head)   //reverse a linked list
    {
        Node* curr=head;
        Node* prev=NULL;
        while(curr)
        {
            Node* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
    
    void add(int val)       // adding values to new linked list
    {
        Node* temp=new Node(val);
        ans->next=temp;
        ans=ans->next;
    }
    
    Node *compute(Node *head)
    {
        // your code goes here
        if (!head)return NULL;
        Node* curr=reverse(head);
        int maxi=curr->data;
        add(maxi);
        curr=curr->next;
        while(curr)
        {
            if (curr->data>=maxi)
            {
                add(curr->data);
                maxi=curr->data;
            }
            curr=curr->next;
        }
        return reverse(dummy->next);
        
    }
    
};
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends