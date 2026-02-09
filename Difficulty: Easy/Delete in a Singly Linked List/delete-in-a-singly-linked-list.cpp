class Solution {
  public:
    Node* deleteNode(Node* head, int x) {

        // If the linked list is empty, nothing to delete
        if (head == nullptr)
            return head;

        // Case 1: If the node to be deleted is the head (x = 1)
        if (x == 1) {
            Node* temp = head;      // Store current head
            head = head->next;      // Move head to next node
            delete temp;            // Free old head
            return head;            // Return new head
        }

        // Temporary pointer to traverse the list
        Node* temp = head;

        // Move temp to the (x-1)th node
        // We stop one node before the node to be deleted
        for (int i = 1; i < x - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }

        // If x is greater than the length of the list
        // or the next node does not exist, do nothing
        if (temp == nullptr || temp->next == nullptr)
            return head;

        // Node to be deleted is temp->next
        Node* curr = temp->next;

        // Skip the node to be deleted
        temp->next = curr->next;

        // Free the memory of the deleted node
        delete curr;

        // Return the updated head
        return head;
    }
};
