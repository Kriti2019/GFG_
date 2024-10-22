//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

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
        if (i >= ip.size()) break;
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


// } Driver Code Ends
/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution{
    public:
    
    // Structure to store information about a subtree
    struct SubtreeInfo {
        int minNode, maxNode, size;
        bool isBST;
        
        SubtreeInfo(int minNode, int maxNode, int size, bool isBST) 
            : minNode(minNode), maxNode(maxNode), size(size), isBST(isBST) {}
    };

    // Helper function to traverse the tree in post-order and find the largest BST
    SubtreeInfo largestBSTSubtree(Node* root) {
        // Base case: An empty tree is a BST with size 0
        if (!root) return SubtreeInfo(INT_MAX, INT_MIN, 0, true);

        // Get information from left and right subtrees
        SubtreeInfo leftInfo = largestBSTSubtree(root->left);
        SubtreeInfo rightInfo = largestBSTSubtree(root->right);

        // Check if the current node can form a valid BST with its left and right subtrees
        if (leftInfo.isBST && rightInfo.isBST && root->data > leftInfo.maxNode && root->data < rightInfo.minNode) {
            // It's a valid BST, so calculate the size of this subtree
            int currentSize = leftInfo.size + rightInfo.size + 1;
            return SubtreeInfo(min(root->data, leftInfo.minNode), max(root->data, rightInfo.maxNode), currentSize, true);
        }

        // If it's not a valid BST, return invalid information
        return SubtreeInfo(INT_MIN, INT_MAX, max(leftInfo.size, rightInfo.size), false);
    }
    
    // Main function to return the size of the largest BST subtree
    int largestBst(Node *root) {
        return largestBSTSubtree(root).size;
    }
};


//{ Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.largestBst(root) << endl;
    }
    return 0;
}

// } Driver Code Ends