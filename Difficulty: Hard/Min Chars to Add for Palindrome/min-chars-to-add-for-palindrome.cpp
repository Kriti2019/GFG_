//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {

public:
    vector<int> computeLPSArray(string str) {
        int n = str.size();
        vector<int> lps(n, 0);
        
        int len = 0;  // length of the previous longest prefix suffix
        int i = 1;
        
        while (i < n) {
            if (str[i] == str[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        
        return lps;
    }
    
    int minChar(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        
        // Concatenate original and reversed string with a special character
        string combined = s + "#" + rev;
        
        // Compute the LPS array for the combined string
        vector<int> lps = computeLPSArray(combined);
        
        // The minimum characters to add is the difference between
        // the string length and the length of the longest palindromic suffix.
        return s.size() - lps.back();
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin >> str;
	    Solution ob;
	    int ans = ob.minChar(str);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends