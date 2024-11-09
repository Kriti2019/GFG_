//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    string minSum(vector<int> &arr) {
        // code here
         sort(arr.begin(), arr.end());
 
    // Two String for storing our two minimum numbers
    string a = "", b = "";
 
    for (int i = 0; i < arr.size(); i += 2) {
        a += (arr[i] + '0');
    }
    for (int i = 1; i < arr.size(); i += 2) {
        b += (arr[i] + '0');
    }
 
    int j = a.length() - 1;
    int k = b.length() - 1;
 
    // as initial carry is zero
    int carry = 0;
    string ans = "";
    while (j >= 0 && k >= 0) {
        int sum = 0;
        sum += (a[j] - '0') + (b[k] - '0') + carry;
        ans += to_string(sum % 10);
        carry = sum / 10;
        j--;
        k--;
    }
 
    // If string b is over and string a is left
    // here we don't need to put here while condition
    // as it would run at max one time. Because the
    // difference between both the strings could be at
    // max 1.
    while (j >= 0) {
        int sum = 0;
        sum += (a[j] - '0') + carry;
        ans += to_string(sum % 10);
        carry = sum / 10;
        j--;
    }
 
    // If string a is over and string b is left
    while (k >= 0) {
        int sum = 0;
        sum += (b[k] - '0') + carry;
        ans += to_string(sum % 10);
        carry = sum / 10;
        k--;
    }
    // if carry is left
    if (carry) {
        ans += to_string(carry);
    }
 
    // to remove leading zeroes as they will be ahead of our
    // sum
    while (!ans.empty() and ans.back() == '0')
        ans.pop_back();
 
    // reverse our final string because we were storing sum
    // from left to right
    reverse(ans.begin(), ans.end());
    return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        string ans = ob.minSum(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends