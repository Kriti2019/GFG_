//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    // Function to find maximum product subarray
    int maxProduct(vector<int> &arr) {
        // Your Code Here
        
         int max_product = arr[0];  // To keep track of the global maximum product
    int min_product = arr[0];  // To keep track of the minimum product ending at the current position
    int result = arr[0];       // To keep track of the result (maximum product found so far)

    // Iterate over the array starting from the second element
    for (int i = 1; i < arr.size(); ++i) {
        // If the current element is negative, swap max_product and min_product
        if (arr[i] < 0) {
            swap(max_product, min_product);
        }

        // Calculate the maximum and minimum product ending at the current position
        max_product = max(arr[i], max_product * arr[i]);
        min_product = min(arr[i], min_product * arr[i]);

        // Update the result with the maximum product found so far
        result = max(result, max_product);
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
        // int n, i;
        // cin >> n;
        // vector<int> arr(n);
        // for (i = 0; i < n; i++) {
        //     cin >> arr[i];
        // }

        vector<int> arr;
        string input;

        // Read array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        auto ans = ob.maxProduct(arr);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends