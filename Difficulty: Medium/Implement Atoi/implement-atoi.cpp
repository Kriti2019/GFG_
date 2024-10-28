//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int myAtoi(char *s) {
        // Your code here
        int i = 0;
        int n = strlen(s);  // Determine the length of the C-string

        // Step 1: Discard leading whitespaces
        while (i < n && s[i] == ' ') {
            i++;
        }

        // Step 2: Check for sign
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i++] == '-') ? -1 : 1;
        }

        // Step 3: Read and accumulate digits
        long long result = 0;  // Using long long to handle overflow cases
        while (i < n && isdigit(s[i])) {
            result = result * 10 + (s[i++] - '0');

            // Step 5: Check for integer overflow
            if (result * sign < INT_MIN) {
                return INT_MIN;
            }
            if (result * sign > INT_MAX) {
                return INT_MAX;
            }
        }

        // Step 6: Return the result
        return static_cast<int>(result * sign);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        char s[20];
        cin >> s;
        Solution ob;
        int ans = ob.myAtoi(s);
        cout << ans << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends