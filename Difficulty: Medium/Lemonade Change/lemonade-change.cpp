//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool lemonadeChange(int N, vector<int> &bills) {
        // code here
        // Initialize a counter
    // for $5 bills
    int five = 0; 
    
    // Initialize a counter
    // for $10 bills
    int ten = 0;   
    
    // Iterate through each customer's bill
    for(int i = 0; i < bills.size(); i++){
        
        // If the customer's
        // bill is $5
        if(bills[i] == 5){
            
            // Increment the
            // count of $5 bills
            five++;  
        }
        
        // If the customer's
        // bill is $10
        else if(bills[i] == 10){
            
            // Check if there are $5
            // bills available to give change
            if(five){
                 // Use one $5 bill
                 // to give change
                five--; 
                // Receive one $10 bill
                ten++;   
            }
            
            // If no $5 bill
            // available, return false
            else return false;  
        }
        
        // If the customer's
        // bill is $20
        else {
            // Check if there are both
            // $5 and $10 bills
            // available to give change
            if(five && ten){
                 // Use one $5 bill
                five--; 
                // Use one $10 bill
                ten--;   
            }
            // If there are not enough $10 bills,
            // check if there are at least
            // three $5 bills available
            else if (five >= 3){
                // Use three $5 bills
                // to give change
                five -= 3;  
            }
            // If unable to give
            // change, return false
            else return false;  
        }
    }
    
    // Return true if all customers
    // are served with correct change
    return true;  
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> bills(N);
        for (int i = 0; i < N; i++) cin >> bills[i];

        Solution obj;
        int ans = obj.lemonadeChange(N, bills);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends