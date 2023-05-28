//{ Driver Code Starts
//Initial Template for C++
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};


/* Function to get the nth node from the last of a linked list*/
int getNthFromLast(struct Node* head, int n);



/* Driver program to test above function*/

// } Driver Code Ends
/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

//Function to find the data of nth node from the end of a linked list.
class Solution{
   int len(Node* head){
        Node* tmp = head;
        int cnt = 0;
        while(tmp){
            tmp = tmp->next;
            cnt++;
        }
        return cnt;
    }
public:
    int getNthFromLast(Node *head, int n)
    {
        int leng = len(head);
        if(leng < n || head == NULL){
            return -1;
        }
        if(leng == n){
            return head->data;
        }
        int k = leng - n;
        Node* tmp = head;
        while(k){
            // q.push(tmp->data);
            k--;
            tmp = tmp->next;
        }
        return tmp->data;
           // Your code here
    }
};



//{ Driver Code Starts.

int main()
{
  int T,i,n,l,k;

    cin>>T;

    while(T--){
    struct Node *head = NULL,  *tail = NULL;

        cin>>n>>k;
        int firstdata;
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
    cout<<obj.getNthFromLast(head, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends