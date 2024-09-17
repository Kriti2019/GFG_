//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int getMinDiff(int arr[], int n, int k) {
        // code here
       if (n == 1) {
        return 0; // No difference if there's only one tower.
    }

    // Sort the array to access smallest and largest elements easily.
    sort(arr, arr + n);

    // Initialize the result as the difference between the largest and smallest elements.
    int result = arr[n-1] - arr[0];

    // Smallest and largest elements after adding/subtracting k.
    int smallest = arr[0] + k;
    int largest = arr[n-1] - k;

    // Traverse the sorted array and compute the minimum and maximum heights.
    for (int i = 0; i < n - 1; i++) {
        // Calculate the new minimum and maximum heights by adjusting the current and next element.
        int minHeight = min(smallest, arr[i+1] - k);
        int maxHeight = max(largest, arr[i] + k);

        // Update the result with the smallest difference.
        result = min(result, maxHeight - minHeight);
    }

    return result;
}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends