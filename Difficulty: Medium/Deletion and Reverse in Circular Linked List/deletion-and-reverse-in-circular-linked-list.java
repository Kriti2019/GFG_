//{ Driver Code Starts
import java.io.*;
import java.util.*;

class Node {
    int data;
    Node next;

    Node(int x) {
        data = x;
        next = null;
    }
}

class LinkedList {
    // Function to print nodes in a given circular linked list
    static void printList(Node head) {
        if (head == null) {
            System.out.println("empty");
            return;
        }
        Node temp = head;
        do {
            System.out.print(temp.data + " ");
            temp = temp.next;
        } while (temp != head);
        System.out.println();
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());

        while (t-- > 0) {
            List<Integer> arr = new ArrayList<>();
            String input = br.readLine();
            StringTokenizer st = new StringTokenizer(input);
            while (st.hasMoreTokens()) {
                arr.add(Integer.parseInt(st.nextToken()));
            }
            int key = Integer.parseInt(br.readLine());
            Node head = new Node(arr.get(0));
            Node tail = head;
            for (int i = 1; i < arr.size(); ++i) {
                tail.next = new Node(arr.get(i));
                tail = tail.next;
            }
            tail.next = head; // Make the list circular
            Solution ob = new Solution();
            Node current = ob.deleteNode(head, key);
            Node rev = ob.reverse(current);
            printList(rev);
        }
    }
}

// } Driver Code Ends


/*class Node
{
    int data;
    Node next;
    Node(int d)
    {
        data=d;next=null;
    }
}*/

class Solution {
    // Function to reverse a circular linked list
    Node reverse(Node head) {
        if (head == null || head.next == head) {
            return head; // Empty list or single node circular list
        }

        Node prev = null;
        Node current = head;
        Node nextNode;
        Node originalHead = head;

        do {
            nextNode = current.next; // Store the next node
            current.next = prev;     // Reverse the link
            prev = current;          // Move prev to the current node
            current = nextNode;      // Move current to the next node
        } while (current != originalHead); // Loop until the list is fully reversed

        // Adjust the next of the original head to the last node
        head.next = prev;
        head = prev;

        return head;
    }

    // Function to delete a node from the circular linked list
    Node deleteNode(Node head, int key) {
        if (head == null) {
            return null; // If the list is empty
        }

        // If the list contains only one node
        if (head.data == key && head.next == head) {
            return null;
        }

        Node current = head;
        Node prev = null;

        // If the node to be deleted is the head node
        if (head.data == key) {
            // Find the last node
            while (current.next != head) {
                current = current.next;
            }
            // Point the last node to the next of head (second node)
            current.next = head.next;
            head = current.next;
            return head;
        }

        // Traverse the list to find the node to delete
        current = head;
        do {
            if (current.data == key) {
                break;
            }
            prev = current;
            current = current.next;
        } while (current != head);

        // If the node to be deleted is found
        if (current.data == key) {
            prev.next = current.next;
        }

        return head;
    }
}