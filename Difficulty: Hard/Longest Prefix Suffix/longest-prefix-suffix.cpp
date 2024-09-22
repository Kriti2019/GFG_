//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int lps(string str) {
        // Your code goes here
        int n = str.size();
    vector<int> lps(n, 0);  // Array to store longest proper prefix that is also suffix.
    
    int len = 0;  // Length of the previous longest prefix suffix.
    int i = 1;
    
    // Loop to calculate lps array.
    while (i < n) {
        if (str[i] == str[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                // Consider the previous longest prefix suffix.
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    
    // The longest proper prefix which is also suffix is in the last element of the lps array.
    return lps[n - 1];

    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;

        Solution ob;

        cout << ob.lps(str) << "\n";
    }

    return 0;
}

// } Driver Code Ends