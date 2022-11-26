//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left
child and a pointer to right child */
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

/* This function is to print the inorder of the tree  */
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}



// } Driver Code Ends
//User function Template for C++

/*
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};
*/


class Solution{
public:
    // function to construct tree from string
   Node* treeFromString(string str){

        

        if ( str.empty() )

            return NULL;

        

        int n = str.length();    

        int num = 0;

        int j = 0;

        

        while( j < n && str[j] != '(' && str[j] != ')' ){

            

            num *= 10;

            num += str[j]- '0';

            j++;

            

        }

        

        Node* root =  new Node(num);

        

        stack<Node*> s;

        s.push(root);

        

        

        for ( int i = j; i<n; i++ ){

            

            

            if ( str[i] == '(' ){

                

                continue;

                

            }

            

            else if ( str[i] == ')' )

                s.pop();

                

            else{

                

                int num = 0;

                int j = i;

                while( str[j] != '(' && str[j] != ')' ){

                    

                    num *= 10;

                    num += str[j]- '0';

                    j++;

                    

                }

                

                i = j-1;

                

                auto node = s.top();

                

                if ( node->left == NULL ){

                    

                    node->left = new Node(num);

                    s.push(node->left);

                    

                }

                

                else{

                    

                    node->right = new Node(num);

                    s.push(node->right);

                    

                }

                

                

            }

            

        }

        

        return root;

        
    }
};

//{ Driver Code Starts.

// Driver Code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution obj;
        Node *root = obj.treeFromString(str);
        inorder(root);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends