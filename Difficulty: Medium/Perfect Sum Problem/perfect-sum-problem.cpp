//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int perfectSum(int arr[], int n, int sum)
	{
        const int MOD = 1e9 + 7;

        // Initialize a vector 'dp' where dp[j] stores the number of ways to make sum 'j'
        vector<int> dp(sum + 1, 0);
        
        // Base case: There's 1 way to make sum 0 (by selecting no elements)
        dp[0] = 1;
        
        // Traverse each element of the array
        for (int i = 0; i < n; i++) {
            // Update the DP array in reverse to avoid overwriting previous results
            for (int j = sum; j >= arr[i]; j--) {
                dp[j] = (dp[j] + dp[j - arr[i]]) % MOD;
            }
        }

        // The final result is the number of ways to form the sum 'sum'
        return dp[sum];
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends