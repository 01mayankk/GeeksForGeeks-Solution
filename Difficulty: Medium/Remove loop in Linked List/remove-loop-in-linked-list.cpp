/*
class Node {
  public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    void removeLoop(Node* head) {
        if (head == nullptr) return;  // check for empty list

        unordered_set<Node*> visited; // store node addresses instead of data

        Node* temp = head;
        visited.insert(temp);

        while (temp->next != nullptr) {
            // if next node is already visited, loop detected
            if (visited.find(temp->next) != visited.end()) {
                temp->next = nullptr;  // remove loop
                break;
            }

            visited.insert(temp->next); // mark next node as visited
            temp = temp->next;          // move forward
        }
    }
};
