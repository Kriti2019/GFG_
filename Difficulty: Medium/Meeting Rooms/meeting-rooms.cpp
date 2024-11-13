//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    bool canAttend(vector<vector<int>> &arr) {
        // Your Code Here
        
        sort(arr.begin(), arr.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    });

    // Check for overlap
    for (int i = 1; i < arr.size(); ++i) {
        // If the start time of the current meeting is less than
        // the end time of the previous meeting, return false
        if (arr[i][0] < arr[i - 1][1]) {
            return false;
        }
    }

    return true;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> arr(n);
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            arr[i].push_back(x);
            arr[i].push_back(y);
        }
        cin.ignore();
        Solution obj;
        bool ans = obj.canAttend(arr);
        if (ans)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends