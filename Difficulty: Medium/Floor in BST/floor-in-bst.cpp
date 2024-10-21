//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};


// } Driver Code Ends
// Function to search a node in BST.
class Solution{

public:
    int floor(Node* root, int key) {
        // Code here
         int floor = -1;
        
        // Traverse the BST until reaching
        // the endor finding the key
        while(root){
            // If the key is found, assign it 
            // as the floor value and return
            if(root->data == key){
                floor = root->data;
                return floor;
            }
            
            // If the key is greater than the current
            // node's value, move to the right subtree
            if(key > root->data){
                // Update the floor with the current node's
                // value and move to the right subtree
                floor = root->data;
                root = root->right;
            }
            else{
                // If the key is smaller than the current
                // node's value, move to the left subtree
                root = root->left;
            }
        }
        // Return the computed floor value
        return floor;
    }
};

//{ Driver Code Starts.

Node *insert(Node *tree, int val) {
    Node *temp = NULL;
    if (tree == NULL) return new Node(val);

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int s;
        cin >> s;
        Solution obj;
        cout << obj.floor(root, s) << "\n";
    }
}

// } Driver Code Ends