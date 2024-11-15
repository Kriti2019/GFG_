//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    // Function returns the second
    // largest elements
   int getSecondLargest(vector<int> &arr) {
    sort(arr.begin(), arr.end());
    int n = arr.size();
    for (int i = n - 2; i >= 0; i--) { // Start from second last element
        if (arr[i] != arr[n - 1]) {     // Check if current element is different from largest
            return arr[i];              // Return the second largest element
        }
    }
    return -1; // Return -1 if there is no second largest
}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int ans = ob.getSecondLargest(arr);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends