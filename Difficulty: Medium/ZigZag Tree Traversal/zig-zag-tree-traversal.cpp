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
//User function Template for C++
/*Structure of the node of the binary tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/


class Solution {
public:
    vector<int> zigZagTraversal(Node* root) {
        vector<int> result;  // To store the final result
        
        // Check if the root is NULL, return an empty result
        if (root == NULL) {
            return result;
        }
        
        // Queue to perform level order traversal
        queue<Node*> nodesQueue;
        nodesQueue.push(root);
        
        // Flag to determine the direction of traversal (left to right or right to left)
        bool leftToRight = true;
        
        // Continue traversal until the queue is empty
        while (!nodesQueue.empty()) {
            // Get the number of nodes at the current level
            int size = nodesQueue.size();
            
            // Vector to store the values of nodes at the current level
            vector<int> row(size);
            
            // Traverse nodes at the current level
            for (int i = 0; i < size; i++) {
                // Get the front node from the queue
                Node* node = nodesQueue.front();
                nodesQueue.pop();
                
                // Determine the index to insert the node's value based on the traversal direction
                int index = leftToRight ? i : (size - 1 - i);
                
                // Insert the node's value at the determined index
                row[index] = node->data;
                
                // Enqueue the left and right children if they exist
                if (node->left) {
                    nodesQueue.push(node->left);
                }
                if (node->right) {
                    nodesQueue.push(node->right);
                }
            }
            
            // Add the current level's values to the result vector
            result.insert(result.end(), row.begin(), row.end());
            
            // Switch the traversal direction for the next level
            leftToRight = !leftToRight;
        }
        
        // Return the final result of zigzag level order traversal
        return result;
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

        vector<int> ans;
        Solution ob;
        ans = ob.zigZagTraversal(root) ;

        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";

        cout << endl;
     
    }
    return 0;
}

// } Driver Code Ends