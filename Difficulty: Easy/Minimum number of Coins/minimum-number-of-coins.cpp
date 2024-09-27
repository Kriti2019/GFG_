//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> minPartition(int V)
    {
        // code here
       vector<int> ans;
    int coins[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
    int n = 10; // Number of denominations

    // Check for invalid inputs
    if (V <= 0) {
        return ans; // Return an empty list if V is non-positive
    }

    // Start from the largest denomination
    for (int i = n - 1; i >= 0; i--) {
        // Use the current denomination as much as possible
        while (V >= coins[i]) {
            V -= coins[i];
            ans.push_back(coins[i]);
        }
    }

    return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends