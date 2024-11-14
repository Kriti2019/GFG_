//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Node {
public:
    Node* links[2];

    Node() {
        for (int i = 0; i < 2; i++) {
            links[i] = nullptr;
        }
    }
};

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    // Insert a number into the Trie
    void insert(int num) {
        Node* node = root;
        for (int i = 31; i >= 0; i--) {  // Start from the most significant bit
            int bit = (num >> i) & 1;
            if (node->links[bit] == nullptr) {
                node->links[bit] = new Node();
            }
            node = node->links[bit];
        }
    }

    // Find the maximum XOR for a given number with any number in the Trie
    int getmax(int num) {
        Node* node = root;
        int maxnum = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            // Try to go to the opposite bit (1-bit) to maximize XOR
            if (node->links[1 - bit] != nullptr) {
                maxnum = maxnum | (1 << i);  // Set the current bit in maxnum
                node = node->links[1 - bit];
            } else {
                node = node->links[bit];
            }
        }
        return maxnum;
    }
};

class Solution
{
    public:
    int max_xor(int arr[] , int n)
    {
        //code here
        Trie trie;
    for (int i=0;i<n;i++) {
        trie.insert(arr[i]);
    }
    int maxi = 0;
    for (int i=0;i<n;i++) {
        maxi = max(maxi, trie.getmax(arr[i]));
    }
    return maxi;
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

		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

        Solution ob;
		cout << ob.max_xor(a, n) << endl;

	
cout << "~" << "\n";
}
}



// } Driver Code Ends