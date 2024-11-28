//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int getAns(vector<int>& arr, int n, int ind, int prev_index, vector<vector<int>>& dp) {
        // Base condition: if we've reached the end of the array
        if (ind == n)
            return 0;

        // If already solved, return the stored value
        if (dp[ind][prev_index + 1] != -1)
            return dp[ind][prev_index + 1];

        // Option 1: Don't take the current element
        int notTake = getAns(arr, n, ind + 1, prev_index, dp);

        // Option 2: Take the current element if it maintains the increasing subsequence
        int take = 0;
        if (prev_index == -1 || arr[ind] > arr[prev_index]) {
            take = arr[ind] + getAns(arr, n, ind + 1, ind, dp);
        }

        // Store and return the maximum sum from both options
        return dp[ind][prev_index + 1] = max(notTake, take);
    }

    int maxSumIS(vector<int>& arr) {
        int n = arr.size();
        // Create a dp table for memoization
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        // Call the helper function starting from the first index and no previous index (-1)
        return getAns(arr, n, 0, -1, dp);
    }
};




//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();

    while (t-- > 0) {
        string str;
        getline(cin, str);

        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.maxSumIS(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends