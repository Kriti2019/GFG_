//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

// Back-end complete function Template for C++

class Solution {
  public:
    long long solve(vector<int>& bt) {
        // code here
        std::sort(bt.begin(), bt.end());

    int n = bt.size();
    long long total_waiting_time = 0;
    long long current_waiting_time = 0;

    // Calculate the waiting times for each process
    for (int i = 1; i < n; ++i) {
        current_waiting_time += bt[i - 1];  // Add previous process's burst time
        total_waiting_time += current_waiting_time;  // Accumulate the waiting time
    }

    // Return the floor of the average waiting time
    return total_waiting_time / n;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> bt(n), p(n);
        for (int i = 0; i < n; i++) {
            cin >> bt[i];
        }
        Solution obj;
        long long ans = obj.solve(bt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends