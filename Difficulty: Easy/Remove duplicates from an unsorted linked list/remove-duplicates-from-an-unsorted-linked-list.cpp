/*
The structure of linked list is the following

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
    Node *removeDuplicates(Node *head) {
        if (head == nullptr) return head; // empty list

        set<int> seen;              // store node values to detect duplicates
        Node* curr = head;
        Node* prev = nullptr;

        while (curr != nullptr) {
            if (seen.find(curr->data) != seen.end()) {
                // duplicate found → remove curr
                prev->next = curr->next;
                delete curr;          //  free memory
                curr = prev->next;    // move curr forward
            } else {
                // not seen before → add to set
                seen.insert(curr->data);
                prev = curr;          // move prev forward
                curr = curr->next;    // move curr forward
            }
        }

        return head;
    }
};
