//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to find maximum of each subarray of size k.
    vector<int> max_of_subarrays(int k, vector<int> &arr) {
        // your code here
        std::deque<int> dq; // Stores indices of potential maximums
    std::vector<int> result;
    
    for (int i = 0; i < arr.size(); ++i) {
        // Remove elements from the back of the deque that are smaller than the current element
        while (!dq.empty() && arr[dq.back()] <= arr[i]) {
            dq.pop_back();
        }
        
        // Add the current element's index to the deque
        dq.push_back(i);
        
        // Remove the element from the front if it's outside the window
        if (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }
        
        // Add the maximum for the current window to the result (only start adding after the first k elements)
        if (i >= k - 1) {
            result.push_back(arr[dq.front()]);
        }
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
        vector<int> res = obj.max_of_subarrays(k, arr);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends