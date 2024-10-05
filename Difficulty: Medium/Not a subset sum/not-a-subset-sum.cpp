//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    long long findSmallest(vector<int> &arr) {
        // Your code goes here.
         long long smallestMissing = 1; // Initialize the smallest missing positive integer

    for (int i = 0; i < arr.size(); ++i) {
        // If the current element is greater than the smallest missing sum, break
        if (arr[i] > smallestMissing) {
            break;
        }
        // Otherwise, add the current element to the smallestMissing
        smallestMissing += arr[i];
    }
    
    return smallestMissing;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }

        Solution ob;
        auto ans = ob.findSmallest(arr);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends