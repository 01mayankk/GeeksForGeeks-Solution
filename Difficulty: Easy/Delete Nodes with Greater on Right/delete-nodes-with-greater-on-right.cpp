/* Structure of a Linked List node
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    
    // Function to reverse a linked list
    Node* reverseList(Node* head) {
        Node* prev = nullptr;
        Node* curr = head;

        while (curr) {
            Node* nextNode = curr->next; // Store next node

            curr->next = prev;           // Reverse current link

            prev = curr;                 // Move prev forward
            curr = nextNode;             // Move curr forward
        }

        // prev becomes the new head
        return prev;
    }

    Node *compute(Node *head) {

        // If list is empty or has only one node,
        // nothing needs to be removed
        if (!head || !head->next)
            return head;

        // -------------------------------------------------
        // Step 1: Reverse the linked list
        // -------------------------------------------------
        // After reversing, nodes that were on the right
        // will now appear on the left.
        head = reverseList(head);

        // Maximum value encountered so far
        int maxi = head->data;

        Node* curr = head;

        // -------------------------------------------------
        // Step 2: Delete nodes smaller than maximum seen
        // -------------------------------------------------
        while (curr && curr->next) {

            // If next node's value is smaller than the
            // maximum value seen so far, it should be removed
            if (curr->next->data < maxi) {

                Node* temp = curr->next;     // Node to delete

                curr->next = temp->next;     // Skip that node

                delete temp;                 // Free memory
            }
            else {
                // This node survives

                curr = curr->next;           // Move forward

                // Update maximum value seen so far
                maxi = curr->data;
            }
        }

        // -------------------------------------------------
        // Step 3: Reverse again to restore original order
        // -------------------------------------------------
        return reverseList(head);
    }
};