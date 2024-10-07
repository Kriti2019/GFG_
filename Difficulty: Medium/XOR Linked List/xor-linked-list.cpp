//{ Driver Code Starts
#include <stdint.h>

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *npx;

    Node(int x) {
        data = x;
        npx = NULL;
    }
};

struct Node *XOR(struct Node *a, struct Node *b) {
    return (struct Node *)((uintptr_t)(a) ^ (uintptr_t)(b));
}

struct Node *insert(struct Node *head, int data);

vector<int> getList(struct Node *head);

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        struct Node *head = NULL;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        while (ss >> number) {
            head = insert(head, number);
        }

        vector<int> vec = getList(head);
        for (int x : vec)
            cout << x << " ";
        cout << endl;
        for (int i = vec.size() - 1; i >= 0; i--) {
            cout << vec[i] << " ";
        }
        cout << "\n";
    }
    return (0);
}

// } Driver Code Ends


/*
Structure of linked list is as
struct Node
{
    int data;
    struct Node* npx;

    Node(int x){
        data = x;
        npx = NULL;
    }
};

Utility function to get XOR of two Struct Node pointer
use this function to get XOR of two pointers
struct Node* XOR (struct Node *a, struct Node *b)
{
    return (struct Node*) ((uintptr_t) (a) ^ (uintptr_t) (b));
}
*/

// function should insert the data to the front of the list
struct Node* insert(struct Node* head, int data) {
    Node* newNode = new Node(data);

    // Insert new node at the beginning
    newNode->npx = XOR(NULL, head);

    // If head is not NULL, update its npx to point to the new node
    if (head != NULL) {
        head->npx = XOR(newNode, XOR(NULL, head->npx));
    }

    // Update head to the new node
    return newNode;
}

// Function to return the linked list elements as a vector
vector<int> getList(struct Node* head) {
    vector<int> result;
    Node* curr = head;
    Node* prev = NULL;
    Node* next;

    // Traverse the list in the forward direction
    while (curr != NULL) {
        result.push_back(curr->data);
        // Calculate next node
        next = XOR(prev, curr->npx);
        // Update prev and curr for the next iteration
        prev = curr;
        curr = next;
    }

    return result;
}
