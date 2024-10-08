//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
   int pairsum(vector<int> &arr) {
    int n = arr.size();
    
    // Initializing the two largest values
    int max1 = max(arr[0], arr[1]);
    int max2 = min(arr[0], arr[1]);
    
    // Loop through the rest of the array to find the two largest numbers
    for (int i = 2; i < n; i++) {
        if (arr[i] > max1) {
            max2 = max1;  // max1 becomes the second largest
            max1 = arr[i]; // arr[i] becomes the largest
        } else if (arr[i] > max2) {
            max2 = arr[i]; // arr[i] becomes the second largest
        }
    }
    
    return max1 + max2;  // Return the sum of the two largest numbers
}

};


//{ Driver Code Starts.
int main() {
    int t;

    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution ob;
        int r = ob.pairsum(arr);
        cout << r << endl;
    }
    return 0;
}
// } Driver Code Ends