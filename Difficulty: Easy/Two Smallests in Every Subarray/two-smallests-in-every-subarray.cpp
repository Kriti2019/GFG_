//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int pairWithMaxSum(vector<int>& arr) {
        // code here
        int n = arr.size();
    
    // If the size of the array is less than 2, return -1
    if (n < 2) {
        return -1;
    }
    
    // Variable to store the maximum sum of adjacent pairs
    int max_sum = INT_MIN;
    
    // Loop through the array and calculate sum of each adjacent pair
    for (int i = 0; i < n - 1; i++) {
        // Sum of current adjacent pair
        int current_sum = arr[i] + arr[i + 1];
        
        // Update max_sum if current_sum is greater
        max_sum = max(max_sum, current_sum);
    }
    
    return max_sum;
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();

    while (tc--) {
        string input;
        getline(cin, input);

        stringstream ss(input);
        vector<int> a;
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution obj;
        int res = obj.pairWithMaxSum(a);
        cout << res << endl;
    }
}
// } Driver Code Ends