//{ Driver Code Starts
// Driver code

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
  public:
   int findOnce(int arr[], int n) {
    // Handle edge cases where array size is 1 or the unique element is at the start or end
    if (n == 1) return arr[0];
    if (arr[0] != arr[1]) return arr[0];
    if (arr[n - 1] != arr[n - 2]) return arr[n - 1];

    // Binary search for the unique element in the rest of the array
    int low = 1, high = n - 2;
    while (low <= high) {
        int mid = (low + high) / 2;

        // Check if the middle element is the unique element
        if (arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1]) {
            return arr[mid];
        }

        // Adjust search space based on the pattern
        if ((mid % 2 == 1 && arr[mid] == arr[mid - 1]) ||
            (mid % 2 == 0 && arr[mid] == arr[mid + 1])) {
            low = mid + 1; // Unique element is in the right half
        } else {
            high = mid - 1; // Unique element is in the left half
        }
    }

    return -1; // In case no unique element is found (shouldn't happen if input is valid)
}

};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int A[n];
        for(int i = 0;i < n;i++)
        {
            cin>>A[i];
        }
        
        Solution ob;
        
        int res = ob.findOnce(A,n);
        cout << res << endl;
    
cout << "~" << "\n";
}
    
    return 0;
}
// } Driver Code Ends