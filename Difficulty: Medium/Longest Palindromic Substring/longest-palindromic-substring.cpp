//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool checkPal(const string &s, int low, int high) {
    while (low < high) {
        if (s[low] != s[high])
            return false;
        low++;
        high--;
    }
    return true;
}
    string longestPalindrome(string s){
        // code here 
         int n = s.size();

    // All substrings of length 1 are palindromes
    int maxLen = 1, start = 0;

    // Nested loop to mark start and end index
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
          
            // Check if the current substring is 
            // a palindrome
            if (checkPal(s, i, j) && (j - i + 1) > maxLen) {
                start = i;
                maxLen = j - i + 1;
            }
        }
    }

    return s.substr(start, maxLen);
    }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.longestPalindrome(S)<<endl;
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends