//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxDistance(vector<int> &arr) {
        // Code here
        unordered_map<int, pair<int, int>> indexMap; // map to store the first and last index of each element
    
    for (int i = 0; i < arr.size(); i++) {
        if (indexMap.find(arr[i]) == indexMap.end()) {
            // If the element is seen for the first time, set both first and last index to i
            indexMap[arr[i]] = {i, i};
        } else {
            // Update the last index of the element
            indexMap[arr[i]].second = i;
        }
    }
    
    int maxDist = 0;
    // Iterate through the map to find the maximum distance
    for (const auto &entry : indexMap) {
        int firstIndex = entry.second.first;
        int lastIndex = entry.second.second;
        maxDist = max(maxDist, lastIndex - firstIndex);
    }
    
    return maxDist;
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
        getline(cin, input);

        stringstream s1(input);
        int num;
        while (s1 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.maxDistance(arr) << endl;
    }
    return 0;
}
// } Driver Code Ends