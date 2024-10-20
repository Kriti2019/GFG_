//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// a node of the doubly linked list
class DLLNode {
  public:
    int data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};


// } Driver Code Ends
// User function Template for C++

/*
// a node of the doubly linked list
class DLLNode
{
public:
    int data;
    DLLNode *next;
    DLLNode *prev;
    DLLNode(int val)
    {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/
class Solution {
  public:
    // function to sort a k sorted doubly linked list
    DLLNode *sortAKSortedDLL(DLLNode *head, int k) {
        // code here
         if (head == nullptr || head->next == nullptr)
            return head;

        // Comparison lambda for the min-heap
        auto cmp = [](DLLNode* a, DLLNode* b) { return a->data > b->data; };
        // Min-heap (priority queue) to store at most k+1 nodes
        std::priority_queue<DLLNode*, std::vector<DLLNode*>, decltype(cmp)> pq(cmp);

        DLLNode* newHead = nullptr; // Head of the sorted list
        DLLNode* last = nullptr;    // Last node of the sorted list

        // Insert the first k+1 nodes into the min-heap
        DLLNode* current = head;
        for (int i = 0; current != nullptr && i <= k; ++i) {
            pq.push(current);
            current = current->next;
        }

        // Process the nodes until the min-heap is empty
        while (!pq.empty()) {
            // Extract the minimum node from the heap
            DLLNode* minNode = pq.top();
            pq.pop();

            // Add the extracted node to the sorted list
            if (newHead == nullptr) {
                newHead = minNode;
                newHead->prev = nullptr;
                last = newHead;
            } else {
                last->next = minNode;
                minNode->prev = last;
                last = minNode;
            }

            // If there are more nodes to process, add the next node to the heap
            if (current != nullptr) {
                pq.push(current);
                current = current->next;
            }
        }

        // Set the next of the last node to nullptr
        last->next = nullptr;

        return newHead;
    }
};

//{ Driver Code Starts.

// Function to insert a node at the end
// of the Doubly Linked List
void push(DLLNode **tailRef, int new_data) {
    // allocate node
    DLLNode *newNode = new DLLNode(new_data);

    // since we are adding at the end,
    // next is NULL
    newNode->next = NULL;

    newNode->prev = (*tailRef);

    // change next of tail node to new node
    if ((*tailRef) != NULL)
        (*tailRef)->next = newNode;

    (*tailRef) = newNode;
}

// Function to print nodes in a given doubly linked list
void printList(DLLNode *head) {
    // if list is empty
    if (head == NULL)
        return;

    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

// Driver
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

        // Read numbers from the input line
        while (ss >> number) {
            arr.push_back(number);
        }

        int k;
        cin >> k;
        cin.ignore();

        DLLNode *head = new DLLNode(arr[0]);
        DLLNode *tail = head;

        // Check if the array is empty
        for (size_t i = 1; i < arr.size(); ++i) {
            push(&tail, arr[i]);
        }
        Solution obj;
        printList(obj.sortAKSortedDLL(head, k));
        cout << "\n";
    }

    return 0;
}

// } Driver Code Ends