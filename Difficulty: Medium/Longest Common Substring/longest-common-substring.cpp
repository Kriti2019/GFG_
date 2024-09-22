//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestCommonSubstr(string s1, string s2) {
        // your code here
        int n = s1.size();
    int m = s2.size();
    
    // Initialize two vectors to store previous and current row values
    vector<int> prev(m+1, 0); // Stores values of the previous row
    vector<int> cur(m+1, 0);  // Stores values of the current row

    int ans = 0; // Initialize the answer variable to store the maximum LCS length found
    
    // Loop through both strings
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s1[i-1] == s2[j-1]){
                int val = 1 + prev[j-1]; // Characters match, increment substring length
                cur[j] = val; // Update the current row with the new value
                ans = max(ans, val); // Update the maximum substring length found so far
            }
            else
                cur[j] = 0; // Characters don't match, substring length becomes 0
        }
        prev = cur; // Update the previous row with the values of the current row
    }
    
    return ans; // Return the length of the Longest Common Substring
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2) << endl;
    }
}
// } Driver Code Ends