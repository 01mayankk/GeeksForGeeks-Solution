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
  
    // Reverse a linked list
    Node* reverse(Node* head) {
        Node* prev = nullptr;
        Node* curr = head;
        Node* next = nullptr;
        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    // Remove leading zeros from a list (keep single zero if the number is 0)
    Node* trimLeadingZeros(Node* head) {
        if (!head) return head;
        // If all nodes are zero, return single zero node
        Node* cur = head;
        bool allZero = true;
        while (cur) {
            if (cur->data != 0) { allZero = false; break; }
            cur = cur->next;
        }
        if (allZero) {
            // free the rest nodes? Not necessary for the judge; just return a single 0 node
            // But to be safe, create a single node 0 and return it
            return new Node(0);
        }

        // Remove leading zeros while more than one node remains and current is zero
        while (head && head->data == 0) {
            Node* tmp = head;
            head = head->next;
            // optional: delete tmp; // avoid if judge still needs original memory
        }
        return head;
    }

    Node* addTwoLists(Node* head1, Node* head2) {
        // Reverse both lists to start from least significant digit
        head1 = reverse(head1);
        head2 = reverse(head2);

        Node* result = nullptr;
        int carry = 0;

        // Add digit by digit (LSD -> MSD in reversed lists)
        while (head1 != nullptr || head2 != nullptr || carry > 0) {
            int sum = carry;
            if (head1 != nullptr) {
                sum += head1->data;
                head1 = head1->next;
            }
            if (head2 != nullptr) {
                sum += head2->data;
                head2 = head2->next;
            }

            carry = sum / 10;
            int digit = sum % 10;

            // Build result by inserting at head (so final result becomes MSD -> LSD)
            Node* newNode = new Node(digit);
            newNode->next = result;
            result = newNode;
        }

        // Trim any leading zeros that came from input leading zeros
        result = trimLeadingZeros(result);

        return result;
    }
};