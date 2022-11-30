//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};



// } Driver Code Ends
/* Following is the Linked list node structure */

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


class Solution{ 
private:
    Node* reverse(Node *start){
        Node *prev=NULL,*curr=start;
        while(curr!=NULL){
            Node *tmp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=tmp;
        }
        return prev;
    }
public:
    void reorderList(Node* head) {
        Node *slow=head,*fast=head->next;
        while(fast&&fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        Node *t1=reverse(slow->next);
        slow->next=NULL;
        Node *t2=head;
        while(t1!=NULL&&t2!=NULL){
            Node *tmp=t2->next;
            Node *tmp1=t1->next;
            t2->next=t1;
            t1->next=tmp;
            t2=tmp;
            t1=tmp1;
        }
    }
};

//{ Driver Code Starts.



/* Function to create a new Node with given data */
struct Node* newNode(int data) {
    struct Node* new_Node = new Node(data);
    new_Node->data = data;
    new_Node->next = NULL;
    return new_Node;
}

void printList(struct Node* Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {

        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(void) {
    int t, n, m, i, x;

    cin >> t;
    while (t--) {
        struct Node* temp, *head;
        cin >> n;
        cin >> x;
        head = new Node(x);
        temp = head;
        for (i = 0; i < n - 1; i++) {
            cin >> x;
            temp->next = new Node(x);
            temp = temp->next;
        }
        
        Solution ob;
        
        ob.reorderList(head);
        printList(head);
        freeList(head);
    }
    return 0;
}

// } Driver Code Ends