/* class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
}; */

// Stack class using Linked List
class myStack {

    Node* topNode;  // pointer to top of stack
    int currentSize; // to maintain stack size

public:

    // Constructor
    myStack() {
        topNode = NULL;      // initially stack is empty
        currentSize = 0;
    }

    // Check if stack is empty
    bool isEmpty() {
        return (topNode == NULL);
    }

    // Push element into stack
    void push(int x) {
        Node* newNode = new Node(x);   // create new node
        
        newNode->next = topNode;       // new node points to current top
        topNode = newNode;             // update top to new node
        
        currentSize++;                 // increase size
    }

    // Pop element from stack
    void pop() {

        if (isEmpty()) {
            cout << "Stack is Empty\n";
            return;
        }

        Node* temp = topNode;          // store current top
        topNode = topNode->next;       // move top pointer
        
        delete temp;                   // free memory
        currentSize--;                 // decrease size
    }

    // Get top element
    int peek() {
        if (isEmpty())
            return -1;

        return topNode->data;
    }

    // Return size of stack
    int size() {
        return currentSize;
    }
};
