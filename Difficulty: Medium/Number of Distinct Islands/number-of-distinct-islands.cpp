//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
      void dfs(int row, int col, int baseRow, int baseCol, vector<vector<int>>& grid, vector<vector<int>>& vis, vector<pair<int, int>>& shape) {
        int n = grid.size();
        int m = grid[0].size();
        // Directions for movement (up, down, left, right)
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, -1, 0, 1};
        
        // Mark the current cell as visited
        vis[row][col] = 1;
        // Store the relative position of the current cell to the base cell
        shape.push_back({row - baseRow, col - baseCol});
        
        // Explore in all four directions
        for (int i = 0; i < 4; i++) {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            
            // Check for valid movement and if the next cell is part of the island
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && !vis[nrow][ncol]) {
                dfs(nrow, ncol, baseRow, baseCol, grid, vis, shape);
            }
        }
    }

  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        set<vector<pair<int, int>>> uniqueShapes;  // Store the shapes of the islands
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    vector<pair<int, int>> shape;  // Store the shape of the current island
                    dfs(i, j, i, j, grid, vis, shape);  // Use DFS to explore the island
                    uniqueShapes.insert(shape);  // Insert the shape into the set
                }
            }
        }
        
        // The size of the set is the number of distinct islands
        return uniqueShapes.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends