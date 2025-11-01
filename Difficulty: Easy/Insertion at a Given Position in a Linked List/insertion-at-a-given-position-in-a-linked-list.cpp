/*
class Node {
  public:
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/

class Solution {
  public:
    Node *insertPos(Node *head, int pos, int val) {
        // ✅ Case 1: Insert at the beginning or when the list is empty
        // If position is 1, the new node becomes the new head.
        // If head is null (empty list), we also create a new head.
        if (pos == 1 || head == nullptr) {
            Node* newNode = new Node(val);  // Create new node
            newNode->next = head;           // Link new node to existing head (may be nullptr)
            return newNode;                 // Return new head
        }

        // ✅ Step 1: Traverse to the (pos - 1)th node
        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp != nullptr; i++) {
            temp = temp->next;  // Move temp to the next node
        }

        // ✅ Step 2: If 'pos' is greater than the length of the list,
        // i.e., temp becomes nullptr, do nothing and return the original list.
        if (temp == nullptr) 
            return head;

        // ✅ Step 3: Insert the new node after 'temp'
        Node* newNode = new Node(val);  // Create new node with given value
        newNode->next = temp->next;     // Link new node to next node
        temp->next = newNode;           // Link previous node to new node

        // ✅ Step 4: Return the (unchanged) head of the list
        return head;
    }
};