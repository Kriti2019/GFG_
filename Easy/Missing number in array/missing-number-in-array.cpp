//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;




// } Driver Code Ends
// User function template for C++

class Solution{
  public:
    int missingNumber(vector<int>& array, int n) {
        // Calculate sum of first n natural numbers
        int sumN = (n * (n + 1)) / 2;

        // Calculate sum of given (n - 1) elements
        int sumArray = 0;
        for (int num : array) {
            sumArray += num;
        }

        // The missing number is the difference between the two sums
        return sumN - sumArray;
        // Your code goes here
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> array(n - 1);
        for (int i = 0; i < n - 1; ++i) cin >> array[i];
        Solution obj;
        cout << obj.missingNumber(array, n) << "\n";
    }
    return 0;
}
// } Driver Code Ends