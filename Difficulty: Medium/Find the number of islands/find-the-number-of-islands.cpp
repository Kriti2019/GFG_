//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
  void dfs(vector<vector<char>>& grid, int x, int y, int n, int m) {
    // Directions for the 8 possible moves (left, right, up, down, and diagonals)
    vector<int> dx = {-1, -1, -1, 0, 0, 1, 1, 1};
    vector<int> dy = {-1, 0, 1, -1, 1, -1, 0, 1};
    
    // Mark the current cell as visited
    grid[x][y] = '0';
    
    // Visit all 8 adjacent cells
    for (int i = 0; i < 8; ++i) {
        int newX = x + dx[i];
        int newY = y + dy[i];
        
        // Check if the new cell is within bounds and is a land ('1')
        if (newX >= 0 && newX < n && newY >= 0 && newY < m && grid[newX][newY] == '1') {
            dfs(grid, newX, newY, n, m);
        }
    }
}
public:
int numIslands(vector<vector<char>>& grid) {
    int n = grid.size();       // Number of rows
    int m = grid[0].size();    // Number of columns
    int numIslands = 0;        // Count of islands
    
    // Iterate through each cell in the grid
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            // If we find an unvisited land cell ('1')
            if (grid[i][j] == '1') {
                // Start DFS to mark all connected land cells
                dfs(grid, i, j, n, m);
                // Increment the island count
                ++numIslands;
            }
        }
    }
    
    return numIslands;
}
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends