//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
   int kthElement(int k, vector<int>& a, vector<int>& b) {
    int n = a.size();
    int m = b.size();

    // Ensure `a` is the smaller array to minimize binary search range
    if (m < n) return kthElement(k, b, a);

    int low = max(0, k - m), high = min(k, n);
    while (low <= high) {
        int mid1 = (low + high) / 2;   // Partition in `a`
        int mid2 = k - mid1;           // Partition in `b` to ensure `left` elements add up to `k`

        // Define left and right bounds for both partitions
        int l1 = (mid1 == 0) ? INT_MIN : a[mid1 - 1];
        int l2 = (mid2 == 0) ? INT_MIN : b[mid2 - 1];
        int r1 = (mid1 == n) ? INT_MAX : a[mid1];
        int r2 = (mid2 == m) ? INT_MAX : b[mid2];

        // Check if valid partition
        if (l1 <= r2 && l2 <= r1) {
            return max(l1, l2);
        } 
        // Adjust binary search range
        else if (l1 > r2) {
            high = mid1 - 1;
        } else {
            low = mid1 + 1;
        }
    }
    return -1; // Fallback if no valid k-th element found
}

};

//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> arr1, arr2;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr1.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            arr2.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(k, arr1, arr2) << endl << "~\n";
    }
    return 0;
}
// } Driver Code Ends