//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to reverse words in a given string.
    string reverseWords(string str) {
        // code here
        vector<string> words;
    string word;
    stringstream ss(str);

    // Split the input string into words based on the dot delimiter
    while (getline(ss, word, '.')) {
        words.push_back(word);
    }

    // Reverse the vector of words
    reverse(words.begin(), words.end());

    // Join the words back into a single string separated by dots
    string result;
    for (int i = 0; i < words.size(); i++) {
        result += words[i];
        if (i != words.size() - 1) {
            result += '.';
        }
    }

    return result;
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
    }
}
// } Driver Code Ends