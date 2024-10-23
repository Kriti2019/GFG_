//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	
{   
    int len = nums.size();
    int n=len;
    map<int, int> map;
    for (int i = 0; i < len; i++)
        map[nums[i]] = i;

    sort(nums.begin(), nums.end());

    // To keep track of visited elements. Initialize
    // all elements as not visited or false.
    bool visited[len] = { 0 };

    // Initialize result
    int ans = 0;
    for (int i = 0; i < len; i++) {

        // already swapped and corrected or
        // already present at correct pos
        if (visited[i] || map[nums[i]] == i)
            continue;

        int j = i, cycle_size = 0;
        while (!visited[j]) {
            visited[j] = true;

            // move to next node
            j = map[nums[j]];
            cycle_size++;
        }

        // Update answer by adding current cycle.
        if (cycle_size > 0) {
            ans += (cycle_size - 1);
        }
    }
    return ans;
}



};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends