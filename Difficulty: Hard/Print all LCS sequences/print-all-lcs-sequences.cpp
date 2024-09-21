//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<string> all_longest_common_subsequences(string s1, string s2) {
       int n = s1.size();
        int m = s2.size();

        // DP table to store the length of LCS
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Fill the dp table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // Use a memoization map to avoid redundant computations
        unordered_map<string, vector<string>> memo;

        // Now we need to collect all longest common subsequences
        return backtrack(dp, s1, s2, n, m, memo);
    }

private:
    vector<string> backtrack(const vector<vector<int>>& dp, const string& s1, const string& s2,
                             int i, int j, unordered_map<string, vector<string>>& memo) {
        // Base case: if we've reached the top-left corner, return an empty string as the base LCS
        if (i == 0 || j == 0) {
            return {""};
        }

        // Generate a unique key for memoization
        string key = to_string(i) + "_" + to_string(j);
        if (memo.find(key) != memo.end()) {
            return memo[key];
        }

        vector<string> result;

        // If characters match, we include this character in the LCS
        if (s1[i - 1] == s2[j - 1]) {
            vector<string> temp = backtrack(dp, s1, s2, i - 1, j - 1, memo);
            for (string& lcs : temp) {
                result.push_back(lcs + s1[i - 1]);
            }
        } else {
            // Otherwise, we explore both the up and left options only if they give the same LCS length
            if (dp[i - 1][j] == dp[i][j]) {
                result = backtrack(dp, s1, s2, i - 1, j, memo);
            }
            if (dp[i][j - 1] == dp[i][j]) {
                vector<string> temp = backtrack(dp, s1, s2, i, j - 1, memo);
                result.insert(result.end(), temp.begin(), temp.end());
            }
        }

        // Remove duplicates by using a set, but this will be minimal since we prune early
        set<string> uniqueResult(result.begin(), result.end());
        result.assign(uniqueResult.begin(), uniqueResult.end());

        // Store the result in memoization map
        memo[key] = result;
        return result;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        vector<string> ans = ob.all_longest_common_subsequences(s, t);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends