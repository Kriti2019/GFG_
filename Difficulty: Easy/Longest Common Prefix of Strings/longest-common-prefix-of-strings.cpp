//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:

    string longestCommonPrefix(vector<string> arr) {
        // your code here
        string ans;
        int n=arr.size();
        if(n==0)return " ";
        for(int i=0;i<arr[0].size();i++){
            char ch=arr[0][i];
            bool match=true;
            for(int j=1;j<n;j++){
                if(arr[j].size()<i || arr[j][i]!=ch){
                    match=false;
                    break;
                    
                }
            }
             if (match == false)
                break;
            else
                ans.push_back(ch);
        }
        return ans.empty() ? "-1" : ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.longestCommonPrefix(arr) << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends