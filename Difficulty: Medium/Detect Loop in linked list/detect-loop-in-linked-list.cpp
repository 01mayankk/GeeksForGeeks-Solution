/*
class Node {
   public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
} */

class Solution {
  public:
    bool detectLoop(Node* head) {
        // code here
        
        if(head == nullptr)
        {
            return false;
        }
        
        unordered_set<Node*>visited;
        Node* temp = head;
        visited.insert(temp);
        while(temp -> next != nullptr)
        {
            if(visited.find(temp->next) != visited.end())
            {
                return true;
            }
            visited.insert(temp);
            temp = temp -> next;
        }
        
        return false;
    }
};