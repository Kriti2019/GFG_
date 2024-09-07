//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long findNth(long long n) {
        // code here.
         long long result = 0;
        long long base = 1;
        
        // Convert the number to base-9 representation
        while (n > 0) {
            result += (n % 9) * base;  // Add the last digit of base-9 equivalent
            n /= 9;                    // Reduce n by a factor of 9
            base *= 10;                // Move to the next digit place in the result
        }
        
        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, ans;
        cin >> n;
        Solution obj;
        ans = obj.findNth(n);
        cout << ans << endl;
    }
}

// } Driver Code Ends