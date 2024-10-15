//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to count the number of subarrays which adds to the given sum.
    int subArraySum(vector<int>& arr, int tar) {
        // Your code here
          unordered_map<int, int> prefix_count;
    int current_sum = 0;
    int count = 0;

    // To handle the case where subarray from the start sums to tar
    prefix_count[0] = 1;

    for (int i = 0; i < arr.size(); i++) {
        current_sum += arr[i];
        
        // Check if there is a prefix sum that equals current_sum - tar
        if (prefix_count.find(current_sum - tar) != prefix_count.end()) {
            count += prefix_count[current_sum - tar];
        }
        
        // Add current_sum to the prefix_count map
        prefix_count[current_sum]++;
    }

    return count;
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
        string ks;
        getline(cin, ks);
        int tar = stoi(ks);
        Solution obj;
        int res = obj.subArraySum(arr, tar);
        cout << res << endl;
    }
    return 0;
}
// } Driver Code Ends