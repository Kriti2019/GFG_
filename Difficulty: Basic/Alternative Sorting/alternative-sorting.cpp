//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    vector<int> alternateSort(vector<int>& arr) {
        // Your code goes here
        sort(arr.begin(), arr.end());  // Sort the array in ascending order
    vector<int> result;
    int i = 0, j = arr.size() - 1;

    // Alternate between largest and smallest elements
    while (i <= j) {
        if (i != j) result.push_back(arr[j--]);  // Add largest remaining element
        result.push_back(arr[i++]);               // Add smallest remaining element
    }

    return result;
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
        vector<int> ans = obj.alternateSort(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends