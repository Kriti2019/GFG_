//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isParenthesisBalanced(string& s) {
        // code here
        unordered_map<char,char>mpp={{')','('},{'}','{'},{']','['}};
        stack<char>st;
        for(char c:s){
            if(mpp.find(c)!=mpp.end()){
                char top=(st.empty())?'#':st.top();
                st.pop();
                if(top!=mpp[c])
                {
                    return false;
                    
                }
                
            }else st.push(c);
            
        }
        return st.empty();
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    string a;
    cin >> t;
    while (t--) {
        cin >> a;
        Solution obj;
        if (obj.isParenthesisBalanced(a))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends