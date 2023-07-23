//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// A Binary Tree Node
struct Node
{
	int data;
	Node* left;
	Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
	Node* temp = new Node;
	temp->data = val;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{
	// Corner Case
	if (str.length() == 0 || str[0] == 'N')
		return NULL;

	// Creating vector of strings from input
	// string after spliting by space
	vector<string> ip;

	istringstream iss(str);
	for (string str; iss >> str; )
		ip.push_back(str);

	// Create the root of the tree
	Node* root = newNode(stoi(ip[0]));

	// Push the root to the queue
	queue<Node*> queue;
	queue.push(root);

	// Starting from the second element
	int i = 1;
	while (!queue.empty() && i < ip.size()) {

		// Get and remove the front of the queue
		Node* currNode = queue.front();
		queue.pop();

		// Get the current node's value from the string
		string currVal = ip[i];

		// If the left child is not null
		if (currVal != "N") {

			// Create the left child for the current node
			currNode->left = newNode(stoi(currVal));

			// Push it to the queue
			queue.push(currNode->left);
		}

		// For the right child
		i++;
		if (i >= ip.size())
			break;
		currVal = ip[i];

		// If the right child is not null
		if (currVal != "N") {

			// Create the right child for the current node
			currNode->right = newNode(stoi(currVal));

			// Push it to the queue
			queue.push(currNode->right);
		}
		i++;
	}

	return root;
}

Node* pointer(Node* root, int n)
{
	if (root == NULL)
		return NULL;

	if (root->data == n)
		return root;

	Node* l = pointer(root->left, n);
	if (l != NULL && l->data == n)
		return l;

	Node* r = pointer(root->right, n);
	return r;

}


// } Driver Code Ends
//User function Template for C++

/*
// A Binary Tree Node
struct Node
{
	int data;
	Node* left;
	Node* right;
};*/

class Solution
{
    public:
    void find_parent(Node *root,Node *&par,Node* target,int dist,int &res)
{
    if(root==NULL)return;
    if(root->left!=NULL&&root->left==target)
    {
        par=root;
        res=dist;
        return;
    }
     if(root->right!=NULL&&root->right==target)
    {
        par=root;
        res=dist;
        return;
    }
    find_parent(root->left,par,target,dist+1,res);
    find_parent(root->right,par,target,dist+1,res);
}
void Solve(Node *root,Node *par,int dist,vector<int> &res)
{
    if(root==NULL)return;
    if(dist<0)
    return;
    if(dist==0)
    {
        if(par!=root)
        {
            if(root->left!=NULL)
            res.emplace_back(root->left->data);
            if(root->right!=NULL)
            res.emplace_back(root->right->data);
            return;
        }
        else
        return;
    }
    Solve(root->left,par,dist-1,res);
    Solve(root->right,par,dist-1,res);
}
    vector<int> printCousins(Node* root, Node* node_to_find)
    {
   Node *par=NULL;
   int dist;
   find_parent(root,par,node_to_find,0,dist);
   if(par==NULL){vector<int> v;v.emplace_back(-1);return v;}
   vector<int> res;
   Solve(root,par,dist,res);
   if(res.size()==0)res.emplace_back(-1);
   return res;
    }
    
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin >> t;
	getchar();
	while (t--)
	{
		int n;
		cin >> n;
		getchar();

		string inp;
		getline(cin, inp);
		
		struct Node* root = buildTree(inp);

		Node* p = pointer(root, n);

        Solution ob;
		vector<int> ans = ob.printCousins(root, p);

		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << " ";

		cout << "\n";


	}

	return 0;
}


// } Driver Code Ends