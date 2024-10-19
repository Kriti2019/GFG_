//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
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
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
          
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

// Function for Inorder Traversal
void printInorder(Node* root)
{
    if(!root)
        return;
        
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
{
    // Queue for BFS traversal, storing the node and its vertical and level information
    queue<pair<Node*,pair<int,int>>> q;
    
    // Map to store nodes based on their vertical and level information
    map<int,map<int,vector<int>>> mpp;  // Use vector instead of multiset to preserve BFS order
    
    // Start with the root node, initial vertical (line) and level are 0
    q.push({root,{0,0}});
    
    while (!q.empty()) {
        auto it = q.front();
        q.pop();
        
        Node* node = it.first;
        int line = it.second.first;   // vertical (line) distance
        int level = it.second.second; // level (depth)
        
        // Insert the node's value into the corresponding vertical and level in the map
        mpp[line][level].push_back(node->data);
        
        // Process the left child, if it exists, move left in terms of vertical and down in level
        if (node->left != NULL) {
            q.push({node->left, {line - 1, level + 1}});
        }
        
        // Process the right child, if it exists, move right in terms of vertical and down in level
        if (node->right != NULL) {
            q.push({node->right, {line + 1, level + 1}});
        }
    }
    
    // Prepare the result vector by traversing the map (sorted by vertical and level)
    vector<int> ans;
    for (auto it : mpp) {
        for (auto p : it.second) {
            ans.insert(ans.end(), p.second.begin(), p.second.end());  // Append values at the end of the result vector
        }
    }
    
    return ans;
}

};



//{ Driver Code Starts.
int main() {
    int t;
    string  tc;
    getline(cin,tc);
    t=stoi(tc);
    while(t--)
    {
        string s;
        getline(cin,s);
        // string c;
        // getline(cin,c);
        Solution obj;
    	Node* root = buildTree(s);
    	
    	vector <int> res = obj.verticalOrder(root);
    	for (int i : res) cout << i << " ";
        cout << endl;
    }
	return 0;
}



// } Driver Code Ends