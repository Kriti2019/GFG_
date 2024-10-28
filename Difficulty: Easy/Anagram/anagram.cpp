//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function is to check whether two strings are anagram of each other or not.
    bool areAnagrams(string& str1, string& str2) {

        // Your code here
        if (str1.length() != str2.length()) {
        return false;  // Different lengths, cannot be anagrams
    }

    const int CHAR_COUNT = 26;  // Assuming only lowercase English letters
    array<int, CHAR_COUNT> count = {0};  

    // Count character frequency in the first string
    for (char ch : str1) {
        count[ch - 'a']++;
    }

    // Decrement character frequency for the second string
    for (char ch : str2) {
        count[ch - 'a']--;
    }

    // Check if all counts are zero (both strings have the same character frequencies)
    for (int freq : count) {
        if (freq != 0) {
            return false;  // Not anagrams
        }
    }

    return true;  // Anagrams
   
        
    }
};

//{ Driver Code Starts.

int main() {

    int t;

    cin >> t;

    while (t--) {
        string c, d;

        cin >> c >> d;
        Solution obj;
        if (obj.areAnagrams(c, d))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends