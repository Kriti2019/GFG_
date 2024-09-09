//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        int low = 0;
    int mid = 0;
    int high = arr.size() - 1;
    
    while (mid <= high) {
        if (arr[mid] == 0) {
            std::swap(arr[low], arr[mid]);  // Swap 0 to the low position
            low++;
            mid++;
        } else if (arr[mid] == 1) {
            mid++;  // 1 is already in the correct place
        } else {  // arr[mid] == 2
            std::swap(arr[mid], arr[high]);  // Swap 2 to the high position
            high--;  // Decrement high, but don't increment mid until the swapped element is checked
        }
    }
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
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        ob.sort012(a);

        int n = a.size();
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }

        cout << endl;
    }
    return 0;
}

// } Driver Code Ends