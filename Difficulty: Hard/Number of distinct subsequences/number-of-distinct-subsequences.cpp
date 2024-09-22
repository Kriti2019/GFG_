//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:	
	int distinctSubsequences(string s)
	{
	    // Your code goes here
	    int n = s.length();
        const int MOD = 1e9 + 7;

        // dp[i] represents the number of distinct subsequences up to the i-th character
        vector<long long> dp(n + 1, 0);
        dp[0] = 1;  // Base case: empty subsequence

        // last occurrence of each character, initialized to -1
        vector<int> last(26, -1);

        for (int i = 1; i <= n; ++i) {
            dp[i] = (dp[i - 1] * 2) % MOD;  // Double the number of subsequences

            // Get the character at the current position
            char current_char = s[i - 1];
            int char_index = current_char - 'a';

            // If the current character appeared before, subtract subsequences that include its last occurrence
            if (last[char_index] != -1) {
                dp[i] = (dp[i] - dp[last[char_index]] + MOD) % MOD;
            }

            // Update the last occurrence of the current character
            last[char_index] = i - 1;
        }

        // The result is dp[n] - 1 (to exclude the empty subsequence)
        return 1 + (dp[n] - 1 + MOD) % MOD;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

        Solution ob;
   		cout << ob.distinctSubsequences(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends