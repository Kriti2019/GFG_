//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    void dfs(int node, vector<int>& ls, vector<vector<int>>& adj, vector<int>& vis) {
        vis[node] = 1;  // Mark the node as visited
        ls.push_back(node);  // Add the current node to the DFS result
        for (auto neighbor : adj[node]) {  // Iterate through neighbors of the current node
            if (!vis[neighbor]) {  // If the neighbor is not visited
                dfs(neighbor, ls, adj, vis);  // Recursively visit the neighbor
            }
        }
    }

    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        int V = adj.size();  // Number of vertices in the graph
        vector<int> vis(V, 0);  // Visited array to track visited nodes
        vector<int> ls;  // To store the DFS traversal order

        // Start DFS from node 0 (assuming connected graph starting from node 0)
        dfs(0, ls, adj, vis);

        return ls;  // Return the DFS traversal order
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(
            V); // Use vector of vectors instead of array of vectors.

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        Solution obj;
        vector<int> ans = obj.dfsOfGraph(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends