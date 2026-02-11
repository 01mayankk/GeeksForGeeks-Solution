/*
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
public:
    Node* intersectPoint(Node* head1, Node* head2) {
        
        if(head1 == nullptr || head2 == nullptr)
            return nullptr;
        
        Node* temp1 = head1;
        Node* temp2 = head2;
        
        // Traverse until both pointers meet
        while(temp1 != temp2)
        {
            // If temp1 becomes NULL, move it to head2
            temp1 = (temp1 == nullptr) ? head2 : temp1->next;
            
            // If temp2 becomes NULL, move it to head1
            temp2 = (temp2 == nullptr) ? head1 : temp2->next;
        }
        
        // Either intersection node OR nullptr
        return temp1;
    }
};
