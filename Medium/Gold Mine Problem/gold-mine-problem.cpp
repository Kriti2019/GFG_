//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        // code here
                if (n == 0 || m == 0) return 0;

        std::vector<std::vector<int>> dp(n, std::vector<int>(m, 0));

        // Initialize the last column of dp with values from M
        for (int i = 0; i < n; ++i) {
            dp[i][m - 1] = M[i][m - 1];
        }

        // Iterate from the second last column to the first column
        for (int j = m - 2; j >= 0; --j) {
            for (int i = 0; i < n; ++i) {
                // Possible moves: diagonal up-right, right, diagonal down-right
                int moves[3] = { i - 1, i, i + 1 };

                int maxGold = 0;
                for (int move : moves) {
                    if (move >= 0 && move < n) {
                        maxGold = std::max(maxGold, dp[move][j + 1]);
                    }
                }

                dp[i][j] = M[i][j] + maxGold;
            }
        }

        // Find the maximum gold in the first column of dp
        int maxAmount = 0;
        for (int i = 0; i < n; ++i) {
            maxAmount = std::max(maxAmount, dp[i][0]);
        }

        return maxAmount;

    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}
// } Driver Code Ends