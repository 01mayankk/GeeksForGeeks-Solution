/*
class Node {
  public:
    int data;
    Node* next;

    // Default constructor
    Node() {
        data = 0;
        next = NULL;
    }

    // Parameterised Constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};
*/
class Solution {
  public:
    Node* insertAtEnd(Node* head, int x) {
        // If list is empty, create new node and return
        if (head == nullptr) {
            return new Node(x);
        }

        Node* temp = head;
        // Traverse to the last node
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        // Append new node at the end
        temp->next = new Node(x);

        return head;
    }
};