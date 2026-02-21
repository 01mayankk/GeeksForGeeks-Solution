/*
structure of the node of the list is as
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* sortedInsert(Node* head, int key) {
        
        Node* newNode = new Node(key);
        
        // Case 1: Empty list
        if(head == nullptr)
            return newNode;
        
        // Case 2: Insert at beginning (correct condition)
        if(key <= head->data)
        {
            newNode->next = head;
            return newNode;
        }
        
        Node* temp = head;
        
        // Move until we reach node BEFORE insertion point
        // We check temp->next, not temp
        while(temp->next != nullptr && temp->next->data < key)
        {
            temp = temp->next;
        }
        
        // Insert safely
        newNode->next = temp->next;
        temp->next = newNode;
        
        return head;
    }
};