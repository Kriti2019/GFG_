//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        // Your code here
    // Edge case: if p is longer than s, return -1
    // Edge case: if p is longer than s, return "-1"
    if (p.size() > s.size()) return "-1";

    // Frequency array for characters in p
    int freqP[26] = {0};
    for (char ch : p) {
        freqP[ch - 'a']++;
    }

    // Variables to track the current window
    int windowFreq[26] = {0};
    int have = 0, need = 0;
    
    // Calculate how many unique characters are needed from p
    for (int i = 0; i < 26; i++) {
        if (freqP[i] > 0) need++;
    }

    int left = 0, right = 0;
    int minLen = INT_MAX, minStart = 0;

    // Sliding window approach
    while (right < s.size()) {
        // Expand the window by including s[right]
        char ch = s[right];
        windowFreq[ch - 'a']++;

        // Check if we have the desired frequency of the current character
        if (freqP[ch - 'a'] > 0 && windowFreq[ch - 'a'] == freqP[ch - 'a']) {
            have++;
        }

        // When all characters of p are found in the current window
        while (have == need) {
            // Check if the current window is the smallest
            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
                minStart = left;
            }

            // Shrink the window from the left
            char leftChar = s[left];
            windowFreq[leftChar - 'a']--;

            // If removing the left character breaks the requirement
            if (freqP[leftChar - 'a'] > 0 && windowFreq[leftChar - 'a'] < freqP[leftChar - 'a']) {
                have--;
            }
            
            left++;
        }

        right++;
    }

    // If no valid window was found, return "-1"
    return minLen == INT_MAX ? "-1" : s.substr(minStart, minLen);
}
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends