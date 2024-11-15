//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++


class Solution
{
    public:
    //Function to merge k sorted arrays.
    struct Element {
    int value; // The value of the element
    int arrayIndex; // The index of the array from which the element is taken
    int elementIndex; // The index of the element in the array
    
    // Comparator to make it a min-heap based on element value
    bool operator>(const Element& other) const {
        return value > other.value;
    }
};

vector<int> mergeKArrays(vector<vector<int>>& arr, int k) {
    // Min-heap to store the smallest elements across the arrays
    priority_queue<Element, vector<Element>, greater<Element>> minHeap;
    
    // Initialize the min-heap with the first element of each array
    for (int i = 0; i < k; i++) {
        if (!arr[i].empty()) {
            minHeap.push({arr[i][0], i, 0});
        }
    }
    
    // Result array to store the merged output
    vector<int> result;
    
    // Continue until the heap is empty
    while (!minHeap.empty()) {
        // Get the smallest element
        Element current = minHeap.top();
        minHeap.pop();
        
        // Add the smallest element to the result
        result.push_back(current.value);
        
        // If the array of the extracted element has more elements, insert the next element in the heap
        if (current.elementIndex + 1 < arr[current.arrayIndex].size()) {
            minHeap.push({arr[current.arrayIndex][current.elementIndex + 1], current.arrayIndex, current.elementIndex + 1});
        }
    }
    
    return result;
}
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    
cout << "~" << "\n";
}
	return 0;
}






// } Driver Code Ends