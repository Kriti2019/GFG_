//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void solve(int col, int n, vector<int>& board, vector<vector<int>>& result) {
    if (col == n) {
        result.push_back(board);  // A valid configuration is found.
        return;
    }

    for (int row = 1; row <= n; ++row) {
        if (isSafe(row, col, board)) {
            board.push_back(row);  // Place queen in this row for current column.
            solve(col + 1, n, board, result);  // Recur to place the next queen.
            board.pop_back();  // Backtrack: Remove queen and try the next row.
        }
    }
}

bool isSafe(int row, int col, vector<int>& board) {
    // Check for conflicts with already placed queens.
    for (int i = 0; i < board.size(); ++i) {
        int queenRow = board[i];  // The row of the queen in the i-th column.
        if (queenRow == row || abs(queenRow - row) == abs(i - col)) {
            // If in the same row or on the same diagonal, return false.
            return false;
        }
    }
    return true;  // The position is safe.
}
    vector<vector<int>> nQueen(int n) {
        // code here
     vector<vector<int>> result;
    vector<int> board;  // To store the solution as a permutation of rows.
    solve(0, n, board, result);
    return result;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends