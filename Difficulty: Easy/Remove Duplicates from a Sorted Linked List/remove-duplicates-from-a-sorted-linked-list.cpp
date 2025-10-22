/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution {
  public:
    // Function to remove duplicates from sorted linked list.
    Node* removeDuplicates(Node* head) {
        if (head == nullptr) return nullptr;  // empty list

        Node* curr = head;

        while (curr != nullptr && curr->next != nullptr) {
            if (curr->data == curr->next->data) {
                // Duplicate found, skip the next node
                Node* temp = curr->next;
                curr->next = curr->next->next;
                delete temp; // free memory
            } else {
                // Move to next node
                curr = curr->next;
            }
        }

        return head;
    }
};
