//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
	// Directions arrays for moving up, down, left, right
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        // Code here
        int n = grid.size();
        
        // Min-heap priority queue to keep track of the minimum cost path
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        
        // Cost array to store minimum cost to reach each cell, initialized to infinity
        vector<vector<int>> cost(n, vector<int>(n, INT_MAX));
        cost[0][0] = grid[0][0];  // Start from the top-left corner
        
        // Start by pushing the top-left corner with its initial cost
        pq.push({grid[0][0], {0, 0}});
        
        while (!pq.empty()) {
            auto current = pq.top();
            pq.pop();        
            // If a cheaper cost to reach (newX, newY) is found, update and push to heap
            int currentCost = current.first;
            int x = current.second.first;
            int y = current.second.second;
            
            // If we reached the bottom-right corner, return the cost
            if (x == n - 1 && y == n - 1) {
                return currentCost;
            }
            
            // Explore the four possible directions
            for (int dir = 0; dir < 4; dir++) {
                int newX = x + dx[dir];
                int newY = y + dy[dir];
                
                // Check if the new position is within the grid bounds
                if (newX >= 0 && newY >= 0 && newX < n && newY < n) {
                    int newCost = currentCost + grid[newX][newY];

                    if (newCost < cost[newX][newY]) {
                        cost[newX][newY] = newCost;
                        pq.push({newCost, {newX, newY}});
                    }
                }
            }
        }
        
        // If we somehow exit the loop without returning, return -1 (shouldn't happen in a valid grid)
        return -1;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends