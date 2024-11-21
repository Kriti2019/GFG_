//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
      vector<int> result; // To store the count of distinct elements
    unordered_map<int, int> freqMap; // To track element frequencies in the current window

    // Initialize the frequency map with the first window
    for (int i = 0; i < k; i++) {
        freqMap[arr[i]]++;
    }
    // Add the count of distinct elements for the first window
    result.push_back(freqMap.size());

    // Slide the window
    for (int i = k; i < arr.size(); i++) {
        // Remove the element going out of the window
        int outElement = arr[i - k];
        freqMap[outElement]--;
        if (freqMap[outElement] == 0) {
            freqMap.erase(outElement); // Remove element with frequency 0
        }

        // Add the new element coming into the window
        int inElement = arr[i];
        freqMap[inElement]++;

        // Add the count of distinct elements for the current window
        result.push_back(freqMap.size());
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

        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        vector<int> res = obj.countDistinct(arr, k);
        for (auto it : res)
            cout << it << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends