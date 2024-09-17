//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        // code here
         int n = arr.size();
        if (n == 1) {
            return 0; // If there's only one tower, no difference.
        }

        // Sort the array to make the smallest and largest elements accessible.
        sort(arr.begin(), arr.end());

        // Initialize result as the current difference between the largest and smallest elements.
        int result = arr[n-1] - arr[0];

        // Consider the new minimum and maximum after adding/subtracting K to the smallest and largest elements.
        int smallest = arr[0] + k;
        int largest = arr[n-1] - k;

        for (int i = 1; i < n; i++) {
            int minHeight = min(smallest, arr[i] - k);
            int maxHeight = max(largest, arr[i-1] + k);
            if (minHeight >= 0) { // Only consider valid heights (non-negative).
                result = min(result, maxHeight - minHeight);
            }
        }

        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, k;
        cin >> k;
        cin.ignore();
        vector<int> a, b, c, d;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution ob;
        auto ans = ob.getMinDiff(a, k);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends