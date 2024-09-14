//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    void rearrange(vector<int> &arr) {
        // code here
         vector<int> pos;  // To store positive and zero elements
    vector<int> neg;  // To store negative elements
    
    // Separate the array into positive/zero and negative arrays
    for (int num : arr) {
        if (num >= 0) {
            pos.push_back(num);
        } else {
            neg.push_back(num);
        }
    }
    
    // Rearrange elements by alternating positive and negative
    int i = 0, j = 0, k = 0;
    
    // Alternate placement of positive and negative elements
    while (i < pos.size() && j < neg.size()) {
        arr[k++] = pos[i++];
        arr[k++] = neg[j++];
    }
    
    // If there are leftover positive elements
    while (i < pos.size()) {
        arr[k++] = pos[i++];
    }
    
    // If there are leftover negative elements
    while (j < neg.size()) {
        arr[k++] = neg[j++];
    }
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
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        ob.rearrange(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends