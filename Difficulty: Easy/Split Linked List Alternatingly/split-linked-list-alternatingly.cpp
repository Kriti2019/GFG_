//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
    // Function to split a linked list into two lists alternately
    vector<Node*> alternatingSplitList(struct Node* head) {
        // Your code here
         if (!head) return {nullptr, nullptr};
        
        // Initialize pointers for both new lists
        Node* first = nullptr;
        Node* second = nullptr;
        Node* currentFirst = nullptr;
        Node* currentSecond = nullptr;
        
        // Use a boolean to alternate between lists
        bool isFirst = true;
        
        Node* current = head;
        while (current) {
            if (isFirst) {
                // If first list is empty, assign head node
                if (!first) {
                    first = current;
                    currentFirst = first;
                } else {
                    // Add node to the first list
                    currentFirst->next = current;
                    currentFirst = currentFirst->next;
                }
            } else {
                // If second list is empty, assign head node
                if (!second) {
                    second = current;
                    currentSecond = second;
                } else {
                    // Add node to the second list
                    currentSecond->next = current;
                    currentSecond = currentSecond->next;
                }
            }
            // Move to the next node in the original list
            current = current->next;
            // Alternate between first and second lists
            isFirst = !isFirst;
        }
        
        // Terminate both lists
        if (currentFirst) currentFirst->next = nullptr;
        if (currentSecond) currentSecond->next = nullptr;
        
        // Return both lists in a vector
        return {first, second};
    }
};


//{ Driver Code Starts.

void printList(struct Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        while (ss >> number) {
            arr.push_back(number);
        }

        struct Node* head = new Node(arr[0]);
        struct Node* tail = head;

        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }

        Solution ob;
        vector<Node*> result = ob.alternatingSplitList(head);
        printList(result[0]);
        printList(result[1]);
    }

    return 0;
}

// } Driver Code Ends