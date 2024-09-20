//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    // Returns count buildings that can see sunlight
    int countBuildings(vector<int> &height) {
        
        // code here
            if (height.size() == 0) return 0;
    
    // The first building will always see the sunrise
    int count = 1;
    int tallest = height[0]; // Track the tallest building so far
    
    // Loop through the buildings starting from the second one
    for (int i = 1; i < height.size(); i++) {
        // If the current building is taller than the tallest seen so far
        if (height[i] > tallest) {
            count++;          // It can see the sunrise
            tallest = height[i]; // Update the tallest building
        }
    }
    
    return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> height;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            height.push_back(number);
        }
        Solution ob;
        int ans = ob.countBuildings(height);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends