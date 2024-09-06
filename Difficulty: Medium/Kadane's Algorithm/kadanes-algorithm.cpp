//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    // Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(vector<int> &arr) {
        // code here...
        // Initialize currentSum and maxSum to the first element of the array
        long long currentSum = arr[0];
        long long maxSum = arr[0];
        
        // Iterate through the array starting from the second element
        for (size_t i = 1; i < arr.size(); i++) {
            // Either add the current element to the current sum, or start a new sum with the current element
            currentSum = std::max((long long)arr[i], currentSum + arr[i]);
            
            // Update maxSum if currentSum is greater than maxSum
            maxSum = std::max(maxSum, currentSum);
        }
        
        // Return the maximum sum found
        return maxSum;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To discard any leftover newline characters
    while (t--)   // while testcases exist
    {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.maxSubarraySum(arr) << endl;
    }
}
// } Driver Code Ends