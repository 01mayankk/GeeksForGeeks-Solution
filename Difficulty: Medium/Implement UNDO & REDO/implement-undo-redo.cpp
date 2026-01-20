class Solution {
private:
    // Stack to store characters in the current document
    stack<char> undoStack;

    // Stack to store undone characters for redo
    stack<char> redoStack;

public:
    // Append a character to the document
    void append(char x) {
        undoStack.push(x);

        // Once a new character is appended,
        // redo history becomes invalid
        while (!redoStack.empty()) {
            redoStack.pop();
        }
    }

    // Undo the most recent append operation
    void undo() {
        if (!undoStack.empty()) {
            char lastChar = undoStack.top();
            undoStack.pop();
            redoStack.push(lastChar);
        }
    }

    // Redo the most recently undone operation
    void redo() {
        if (!redoStack.empty()) {
            char charToRestore = redoStack.top();
            redoStack.pop();
            undoStack.push(charToRestore);
        }
    }

    // Read the current document content
    string read() {
        string result;
        stack<char> temp = undoStack;

        // Stack stores characters in reverse order
        while (!temp.empty()) {
            result.push_back(temp.top());
            temp.pop();
        }

        // Reverse to get correct order
        reverse(result.begin(), result.end());

        return result;
    }
};
