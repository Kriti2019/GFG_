//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited) {
        visited[node] = true;
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited);
            }
        }
    }

    // Function to check if the graph is strongly connected
    bool isStronglyConnected(int start, vector<vector<int>> &adj, vector<bool> &visited) {
        // Reset visited array
        fill(visited.begin(), visited.end(), false);
        
        // Perform DFS starting from the start node
        dfs(start, adj, visited);

        // Check if all nodes with edges are visited
        for (int i = 0; i < 26; i++) {
            if (!visited[i] && (adj[i].size() > 0)) {
                return false;
            }
        }
        return true;
    }

    int isCircle(vector<string> &arr) {
        vector<int> inDegree(26, 0), outDegree(26, 0);  // For each character, its in-degree and out-degree
        vector<vector<int>> adj(26);                    // Adjacency list for the graph
        vector<bool> visited(26, false);                // To track visited nodes
        
        // Build the graph
        for (string &s : arr) {
            int first = s[0] - 'a';   // Convert first character to index
            int last = s.back() - 'a'; // Convert last character to index
            adj[first].push_back(last);  // Create a directed edge from first to last
            outDegree[first]++;          // Increment out-degree of the first character
            inDegree[last]++;            // Increment in-degree of the last character
        }

        // Check that for every node, in-degree equals out-degree
        for (int i = 0; i < 26; i++) {
            if (inDegree[i] != outDegree[i]) {
                return 0;  // If they are not equal, return false
            }
        }

        // Now check if the graph is strongly connected
        // We can start from any node with edges, so let's find the first node with at least one outgoing edge
        int start = -1;
        for (int i = 0; i < 26; i++) {
            if (outDegree[i] > 0) {
                start = i;
                break;
            }
        }

        // If no node has outgoing edges, return 1 (since all strings are isolated)
        if (start == -1) {
            return 1;
        }

        // Check if the graph is strongly connected starting from 'start' node
        if (!isStronglyConnected(start, adj, visited)) {
            return 0;
        }

        // Create the reverse graph for checking reverse connectivity
        vector<vector<int>> reverseAdj(26);
        for (int u = 0; u < 26; u++) {
            for (int v : adj[u]) {
                reverseAdj[v].push_back(u);  // Reverse the direction of edges
            }
        }

        // Check if the reverse graph is also strongly connected
        if (!isStronglyConnected(start, reverseAdj, visited)) {
            return 0;
        }

        // If all checks passed, the strings can form a circle
        return 1;
    }

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> A;
        string s;

        for (int i = 0; i < N; i++) {
            cin >> s;
            A.push_back(s);
        }

        Solution ob;
        cout << ob.isCircle(A) << endl;
    }
    return 0;
}
// } Driver Code Ends