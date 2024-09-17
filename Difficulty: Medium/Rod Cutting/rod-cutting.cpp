//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int cutRod(int price[], int n) {
        //code here
        vector<int> dp(n + 1, 0);

    // Iterate over each length i (from 1 to n)
    for (int i = 1; i <= n; i++) {
        // Try cutting the rod at each possible length j
        for (int j = 1; j <= i; j++) {
            dp[i] = max(dp[i], price[j - 1] + dp[i - j]);
        }
    }

    // Return the maximum price obtainable for a rod of length n
    return dp[n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends