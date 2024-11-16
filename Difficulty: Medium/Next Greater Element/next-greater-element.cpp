//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the next greater element for each element of the array.
   

vector<int> nextLargerElement(vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, -1); // Initialize the result array with -1s
    stack<int> s; // Stack to store indices

    for (int i = 0; i < n; ++i) {
        // While the stack is not empty and the current element is greater than the element
        // at the index stored at the top of the stack, set the next greater for that index
        while (!s.empty() && arr[i] > arr[s.top()]) {
            result[s.top()] = arr[i];
            s.pop();
        }
        s.push(i); // Push the current index onto the stack
    }

    return result;
}

};

//{ Driver Code Starts.

int main() {
    int t; // Number of test cases
    cin >> t;
    cin.ignore(); // Ignore the newline after reading t
    while (t--) {
        vector<int> a;
        string input;

        // Reading the entire input line for the array
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num); // Read the array elements from input string

        Solution obj;
        vector<int> result = obj.nextLargerElement(a);

        // Print the result in the required format
        for (int i = 0; i < result.size(); i++) {
            if (i != 0)
                cout << " ";
            cout << result[i];
        }
        cout << endl;        // Ensure new line after each test case output
        cout << "~" << endl; // Ensure new line after each test case output
    }

    return 0;
}

// } Driver Code Ends