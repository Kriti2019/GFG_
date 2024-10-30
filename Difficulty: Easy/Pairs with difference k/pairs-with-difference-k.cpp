//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    /* Returns count of pairs with difference k  */
    int countPairsWithDiffK(vector<int>& arr, int k) {
        // code here
        unordered_map<int, int> freq;
    for (int x : arr) {
        freq[x]++;
    }
    long long count = 0;
    if (k == 0) {
        for (auto it : freq) {
            long long f = it.second;
            count += f * (f - 1) / 2;
        }
    } else {
        for (auto it : freq) {
            int x = it.first;
            if (freq.find(x + k) != freq.end()) {
                count += (long long)freq[x] * freq[x + k];
            }
        }
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
        int k = stoi(ks);
        Solution ob;
        auto ans = ob.countPairsWithDiffK(arr, k);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends