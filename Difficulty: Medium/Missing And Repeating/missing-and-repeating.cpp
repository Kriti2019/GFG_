//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
       int n = arr.size();
    int xor1 = 0;
    
    // Step 1: XOR all the array elements and numbers from 1 to n
    for (int i = 0; i < n; i++) {
        xor1 ^= arr[i]; // XOR of array elements
        xor1 ^= (i + 1); // XOR of numbers from 1 to n
    }
    
    // Step 2: xor1 now contains A ^ B, where A is the missing number, and B is the repeating number
    // Find the rightmost set bit in xor1 (which distinguishes between A and B)
    int set_bit_no = xor1 & ~(xor1 - 1);
    
    int x = 0, y = 0; // x and y are the two unique numbers (A and B)
    
    // Step 3: Divide the numbers into two sets based on the set bit
    for (int i = 0; i < n; i++) {
        if (arr[i] & set_bit_no) {
            x ^= arr[i]; // XOR for set with the set bit
        } else {
            y ^= arr[i]; // XOR for set without the set bit
        }
        if ((i + 1) & set_bit_no) {
            x ^= (i + 1);
        } else {
            y ^= (i + 1);
        }
    }
    
    // Step 4: Determine which is the missing number and which is the repeating number
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return {x, y}; // x is the repeating number, y is the missing number
        }
    }
    
    return {y, x}; // y is the repeating number, x is the missing number

        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends