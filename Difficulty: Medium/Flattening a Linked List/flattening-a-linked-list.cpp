/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
*/
class Solution {
public:

    // Function to merge two sorted linked lists
    // using bottom pointers only
    Node* merge(Node* a, Node* b) {

        // If first list is empty, return second
        if (a == NULL) return b;

        // If second list is empty, return first
        if (b == NULL) return a;

        Node* result;

        // Compare data values of both nodes
        if (a->data < b->data) {

            // If a has smaller value, choose a
            result = a;

            // Merge rest of a->bottom with b
            result->bottom = merge(a->bottom, b);
        } 
        else {

            // If b has smaller or equal value, choose b
            result = b;

            // Merge a with rest of b->bottom
            result->bottom = merge(a, b->bottom);
        }

        // Important: next pointer must be NULL
        // because final list should use bottom pointers only
        result->next = NULL;

        return result;
    }

    // Main function to flatten the linked list
    Node *flatten(Node *root) {

        // Base case:
        // If list is empty or only one head node exists
        if (root == NULL || root->next == NULL)
            return root;

        // Recursively flatten the list on the right side
        root->next = flatten(root->next);

        // Merge current list with flattened right list
        root = merge(root, root->next);

        // Return the head of flattened list
        return root;
    }
};
