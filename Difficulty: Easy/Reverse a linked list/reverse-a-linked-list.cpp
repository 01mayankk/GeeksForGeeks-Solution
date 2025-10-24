/*
class Node {
 public:
    int data ;
    Node *next ;

    Node(int x) {
        data = x ;
        next = NULL ;
    }
};
*/

class Solution {
  public:
    Node* reverseList(Node* head) {
        // code here
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;

        while (curr != NULL) {
            next = curr->next;   // store next node
            curr->next = prev;   // reverse the link
            prev = curr;         // move prev forward
            curr = next;         // move curr forward
        }

        return prev;  // new head of reversed list
    }
};