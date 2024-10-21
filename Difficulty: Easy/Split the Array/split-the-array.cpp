//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

const int MOD = 1e9 + 7;

// Function to compute power (base^exp) % MOD using binary exponentiation
int power(int base, int exp, int mod) {
    long long result = 1;
    long long baseMod = base % mod;

    while (exp > 0) {
        if (exp % 2 == 1) {  // If exp is odd, multiply result by baseMod
            result = (result * baseMod) % mod;
        }
        baseMod = (baseMod * baseMod) % mod;  // Square the base
        exp /= 2;
    }

    return result;
}

int countgroup(vector<int>& arr) {
    int n = arr.size();
    
    // Step 1: Compute totalXOR of the array
    int totalXOR = 0;
    for (int num : arr) {
        totalXOR ^= num;
    }
    
    // Step 2: If totalXOR is not 0, there is no valid partition
    if (totalXOR != 0) {
        return 0;
    }
    
    // Step 3: Calculate the number of valid splits as (2^(n-1) - 1) % MOD
    int validSplits = power(2, n - 1, MOD);
    
    // Subtract 1 to exclude the case where one group is empty
    return (validSplits - 1 + MOD) % MOD;
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
        int ans = obj.countgroup(arr);
        cout << ans << endl;
    }
}

// } Driver Code Ends