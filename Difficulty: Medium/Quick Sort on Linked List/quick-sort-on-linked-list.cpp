//{ Driver Code Starts
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/* a node of the singly linked list */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* A utility function to insert a node at the beginning of linked list */
void push(struct Node*& head_ref, int new_data) {
    /* allocate node */
    struct Node* new_node = new Node(new_data);

    /* link the old list off the new node */
    new_node->next = head_ref;

    /* move the head to point to the new node */
    head_ref = new_node;
}

/* A utility function to print linked list */
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Partitions the list taking the last element as the pivot
struct Node* partition(struct Node* head, struct Node* end, struct Node*& newHead,
                       struct Node*& newEnd) {
    struct Node* pivot = end;
    struct Node *prev = NULL, *cur = head, *tail = pivot;

    // During partition, both the head and end of the list might change
    // which is updated in the newHead and newEnd variables
    while (cur != pivot) {
        if (cur->data < pivot->data) {
            // First node that has a value less than the pivot - becomes the new head
            if (newHead == NULL)
                newHead = cur;

            prev = cur;
            cur = cur->next;
        } else { // If cur node is greater than pivot
            // Move cur node to next of tail, and change tail
            if (prev)
                prev->next = cur->next;
            struct Node* tmp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }

    // If the pivot data is the smallest element in the current list, pivot becomes the
    // head
    if (newHead == NULL)
        newHead = pivot;

    // Update newEnd to the current last node
    newEnd = tail;

    // Return the pivot node
    return pivot;
}


// } Driver Code Ends


/*
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/
class Solution {
public:
    // QuickSort function to sort the linked list
    Node* quickSort(Node* head) {
         Node* tail = getTail(head);
    
      // Call the helper function to sort the list
    quickSortHelper(head, tail);
    return head;
    }

private:
    // Function to get the tail node of a linked list
   Node* getTail(Node* cur) {
    while (cur != nullptr && cur->next != nullptr)
        cur = cur->next;
    return cur;
}

// Partitions the list taking the first element as the pivot
Node* partition(Node* head, Node* tail) {
  
      // Select the first node as the pivot node
    Node* pivot = head;
  
    // 'pre' and 'curr' are used to shift all 
      // smaller nodes' data to the left side of the pivot node
    Node* pre = head;
    Node* curr = head;

    // Traverse the list until you reach the node after the tail
    while (curr != tail->next) {
        
        if (curr->data < pivot->data) {
            swap(curr->data, pre->next->data);
          
              // Move 'pre' to the next node
            pre = pre->next;
        }
        
          // Move 'curr' to the next node
        curr = curr->next;
    }
    
    swap(pivot->data, pre->data);
    
      // Return 'pre' as the new pivot
    return pre;
}

// Helper function for quick sort
void quickSortHelper(Node* head, Node* tail) {
  
    // Base case: if the list is empty or consists of a single node
    if (head == nullptr || head == tail) {
        return;
    }
    
      // Call partition to find the pivot node
    Node* pivot = partition(head, tail);
    
      // Recursive call for the left part of the list (before the pivot)
    quickSortHelper(head, pivot);
    
      // Recursive call for the right part of the list (after the pivot)
    quickSortHelper(pivot->next, tail);
}
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after reading t

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }

        Solution ob;
        head = ob.quickSort(head);

        printList(head);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends