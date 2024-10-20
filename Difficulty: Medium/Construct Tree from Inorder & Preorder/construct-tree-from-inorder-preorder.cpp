//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{

    public:
    Node* buildTree(int in[], int pre[], int n)
    {
        int preIndex = 0; // Index to keep track of the current root in preorder traversal
        // Call the helper function to construct the tree
        return buildTreeHelper(in, pre, 0, n - 1, preIndex, n);
    }
    
    private:
    // Helper function to recursively build the tree
    Node* buildTreeHelper(int in[], int pre[], int inStart, int inEnd, int& preIndex, int n)
    {
        // Base case: if there are no elements to construct the tree
        if (inStart > inEnd || preIndex >= n)
            return nullptr;
        
        // The current node's value is at preIndex in preorder traversal
        int rootVal = pre[preIndex++];
        Node* root = new Node(rootVal);
        
        // If this node has no children, return it
        if (inStart == inEnd)
            return root;
        
        // Find the index of the root in inorder traversal
        int inIndex = search(in, inStart, inEnd, rootVal);
        
        // Recursively build the left and right subtrees
        root->left = buildTreeHelper(in, pre, inStart, inIndex - 1, preIndex, n);
        root->right = buildTreeHelper(in, pre, inIndex + 1, inEnd, preIndex, n);
        
        return root;
    }
    
    // Function to find the index of a value in inorder traversal
    int search(int arr[], int start, int end, int value)
    {
        for (int i = start; i <= end; ++i)
        {
            if (arr[i] == value)
                return i;
        }
        return -1; // Value not found (should not happen in valid input)
    }


};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends