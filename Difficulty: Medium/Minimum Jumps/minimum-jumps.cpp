//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution {
  public:
    int minJumps(vector<int>& arr) {
        // Your code here
         int n = arr.size();
    
    // If the array has only one element, no jumps are needed
    if (n == 1) return 0;

    // If the first element is 0, we can't move forward
    if (arr[0] == 0) return -1;
    
    int maxReach = arr[0];  // The farthest point we can reach
    int steps = arr[0];     // Steps we can still take in the current jump
    int jumps = 1;          // At least one jump is needed to start
    
    // Start iterating from the second element
    for (int i = 1; i < n; i++) {
        // If we have reached the end of the array
        if (i == n - 1) return jumps;
        
        // Update the maximum reachable index
        maxReach = max(maxReach, i + arr[i]);
        
        // We use a step to get to the current index
        steps--;
        
        // If no steps are left
        if (steps == 0) {
            // We must take another jump
            jumps++;
            
            // If we can't reach further, return -1
            if (i >= maxReach) return -1;
            
            // Re-initialize the steps to the amount of steps we can take from here
            steps = maxReach - i;
        }
    }
    
    return -1;  // If we never reach the last index
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, i, j;
        vector<int> arr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minJumps(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends