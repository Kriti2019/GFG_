//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#include<sstream>
class Solution {
  public:
    // Function to reverse words in a given string.
    string reverseWords(string str) {
        // code here
        stringstream ss(str);
        vector<string>s;
        string word;
        while(getline(ss, word, '.')){
            s.push_back(word);
        }
        reverse(s.begin(),s.end());
        
        string ans;
        for (size_t i = 0; i < s.size(); ++i) {
            ans += s[i];
            if (i < s.size() - 1) {
                ans += '.';
            }
        }
     return ans;   
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.reverseWords(s) << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends