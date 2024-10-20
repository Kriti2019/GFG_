//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL)
        return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}


// } Driver Code Ends
/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    // Function to return a tree created from postorder and inorder traversals.
    Node* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // Map to store the index of each value in inorder traversal for quick lookup.
        unordered_map<int, int> inorderIndexMap;
        for (int i = 0; i < inorder.size(); ++i) {
            inorderIndexMap[inorder[i]] = i;
        }
        // Initialize the postorder index to the last element.
        int postorderIndex = postorder.size() - 1;
        // Build the tree using a helper function.
        return buildTreeHelper(inorder, 0, inorder.size() - 1,
                               postorder, postorderIndex, inorderIndexMap);
    }
    
  private:
    // Helper function to recursively build the tree.
    Node* buildTreeHelper(vector<int>& inorder, int inorderStart, int inorderEnd,
                          vector<int>& postorder, int& postorderIndex,
                          unordered_map<int, int>& inorderIndexMap) {
        // Base case: if there are no elements to construct the tree.
        if (inorderStart > inorderEnd || postorderIndex < 0) {
            return nullptr;
        }
        // Get the current root value from postorder traversal.
        int rootVal = postorder[postorderIndex--];
        // Create the root node.
        Node* root = new Node(rootVal);
        // Find the index of the root in inorder traversal.
        int inorderIndex = inorderIndexMap[rootVal];
        // Recursively build the right and left subtrees.
        // Note: Build right subtree before left subtree because we are decrementing postorderIndex.
        root->right = buildTreeHelper(inorder, inorderIndex + 1, inorderEnd,
                                      postorder, postorderIndex, inorderIndexMap);
        root->left = buildTreeHelper(inorder, inorderStart, inorderIndex - 1,
                                     postorder, postorderIndex, inorderIndexMap);
        return root;
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);

        stringstream ss(input);
        vector<int> inorder;
        int number;
        while (ss >> number) {
            inorder.push_back(number);
        }

        getline(cin, input);
        stringstream ss2(input);
        vector<int> postorder;
        while (ss2 >> number) {
            postorder.push_back(number);
        }
        Solution obj;
        Node* root = obj.buildTree(inorder, postorder);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends