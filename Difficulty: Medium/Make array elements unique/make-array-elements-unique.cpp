//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minIncrements(vector<int>& arr) {
        // Code here
        int n = arr.size();
    int cnt = 0;
    
    // Find the maximum element in the array
    int mx = *max_element(arr.begin(), arr.end());
    
    // Create a frequency array
    vector<int> freq(n + mx, 0);
    
    // Find the frequency of all elements from the array
    for (int ele : arr) 
        freq[ele]++;
      
    for (int num = 0; num < freq.size(); num++) {
        
        // If there is more than one occurrence of num
        if (freq[num] > 1) {
            
            // Increment all extra occurrences by 1 
            freq[num + 1] += freq[num] - 1;
            
            // Count these increment operations
            cnt += freq[num] - 1;
            freq[num] = 1;
        }
    }
  
    return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        int ans = ob.minIncrements(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends