//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string roundToNearest(string str) {
     int lastDigit = str.back() - '0';
    
    // If the last digit is less than 5, round down
    if (lastDigit < 5) {
        str.back() = '0';  // Set the last digit to 0
    } 
    // If the last digit is greater than 5, round up
    else if (lastDigit > 5) {
        str.back() = '0';  // Set the last digit to 0
        // Perform the carry operation to round up the number
        int i = str.length() - 2;  // Start from the second last digit
        while (i >= 0 && str[i] == '9') {
            str[i] = '0';
            i--;
        }
        // If we haven't reached the start, increment the current digit
        if (i >= 0) {
            str[i]++;
        } else {
            // If we reach the start of the string and all digits were 9, add a '1' to the front
            str = '1' + str;
        }
    } 
    // If the last digit is exactly 5, round down (per problem statement)
    else {
        str.back() = '0';  // Set the last digit to 0 (round down)
    }
    
    return str;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.roundToNearest(str) << endl;
    }

    return 0;
}
// } Driver Code Ends