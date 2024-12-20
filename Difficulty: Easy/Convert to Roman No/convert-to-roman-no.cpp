//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
 
string convertToRoman(int n) {
    // Roman numerals and their corresponding values
    pair<int, string> romanValues[] = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
        {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
        {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
    };

    string result;

    // Iterate over each Roman numeral
    for (auto &pair : romanValues) {
        int value = pair.first;
        string symbol = pair.second;

        // Append symbol while the value fits into n
        while (n >= value) {
            result += symbol;
            n -= value;
        }
    }

    return result;
}

};

//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int N;
		cin>>N;
		Solution ob;
    	cout << ob.convertToRoman(N) << endl;
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends