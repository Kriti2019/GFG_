//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int rotateDelete(vector<int> &arr) {
        // Your code here
         int n = arr.size();
        int k = 1;

        while (n > 1) {
            // Rotate right by inserting the last element at the front
            arr.insert(arr.begin(), arr[n - 1]);
            arr.pop_back();

            // Calculate the index to remove
            int index = (n - k);
            if (index < 0)
                index = 0;

            // Remove the element
            arr.erase(arr.begin() + index);

            // Increment counters
            k++;
            n--;
        }

        return arr[0];
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.rotateDelete(arr);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends