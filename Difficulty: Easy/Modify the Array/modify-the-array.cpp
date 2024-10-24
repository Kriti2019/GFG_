//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> modifyAndRearrangeArray(vector<int> &arr) {
        // Complete the function
         int n = arr.size();

    // First pass: Modify the array according to the given rules
    for (int i = 0; i < n - 1; i++) {
        // Check if current and next elements are valid and equal
        if (arr[i] != 0 && arr[i] == arr[i + 1]) {
            arr[i] *= 2;       // Double the current element
            arr[i + 1] = 0;    // Set the next element to 0
        }
    }

    // Second pass: Shift all non-zero elements to the front
    int index = 0; // Position to place the next non-zero element
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            arr[index++] = arr[i];
        }
    }

    // Fill the remaining positions with zeros
    while (index < n) {
        arr[index++] = 0;
    }

    return arr;
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        vector<int> ans = obj.modifyAndRearrangeArray(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends