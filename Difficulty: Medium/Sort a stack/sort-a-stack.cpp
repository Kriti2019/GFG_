//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);

cout << "~" << "\n";
}
}
// } Driver Code Ends


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */

// Function to insert an element in a sorted manner
void sortedInsert(stack<int> &s, int element) {
    // Base case: If stack is empty or top element is smaller than element
    if (s.empty() || s.top() <= element) {
        s.push(element);
    } else {
        // If top is greater, pop the top and recurse
        int top = s.top();
        s.pop();
        sortedInsert(s, element);
        
        // Push the popped element back
        s.push(top);
    }
}

// Function to sort the stack using recursion
void SortedStack::sort() {
    if (!s.empty()) {
        // Pop the top element
        int top = s.top();
        s.pop();
        
        // Sort the remaining stack
        sort();
        
        // Insert the popped element back in sorted order
        sortedInsert(s, top);
    }
}
