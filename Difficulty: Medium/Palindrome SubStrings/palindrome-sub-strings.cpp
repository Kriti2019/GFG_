//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


// User function Template for C++

class Solution {
    private:
    void expandAroundCenter(char s[], int left, int right,int n, vector<string>& palindromes) {
        while (left >= 0 && right < n && s[left] == s[right]) {
            if (right - left + 1 > 1) {  // Only add if length > 1
                palindromes.push_back(string(s + left, s + right + 1));
            }
            left--;
            right++;
        }
    }
  public:
    int CountPS(char s[], int n) {
        // code here
        if(n==0 or n==1)return 0;
        vector<string>st;
         for (int i = 0; i <n; i++) {
            // Find all odd-length palindromes centered at i, but ignore single characters
            expandAroundCenter(s, i, i,n, st);

            // Find all even-length palindromes centered between i and i + 1
            expandAroundCenter(s, i, i + 1,n, st);
        }
        return st.size();
    }
    
    
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        char S[N + 1];
        cin >> S;
        Solution ob;
        cout << ob.CountPS(S, N) << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends