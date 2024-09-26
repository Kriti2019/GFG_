//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find maximum number of consecutive steps
    // to gain an increase in altitude with each step.
    int maxStep(vector<int>& arr) {
        // Your code here
    int n = arr.size();
    int max_steps = 0;  // To store the maximum consecutive steps
    int current_steps = 0;  // To count the current sequence of increasing steps

    for (int i = 1; i < n; ++i) {
        if (arr[i] > arr[i - 1]) {
            // If current building is taller than the previous, increment the current steps
            current_steps++;
        } else {
            // Update max_steps if current_steps is larger, then reset current_steps
            max_steps = std::max(max_steps, current_steps);
            current_steps = 0;
        }
    }

    // After the loop, check if the last sequence was the longest
    max_steps = std::max(max_steps, current_steps);

    return max_steps;
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
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        cout << ob.maxStep(arr) << endl;
    }
    return 0;
}
// } Driver Code Ends