/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
  
    // Step 1: Build parent mapping and find target node
    Node* buildParentMap(Node* root, unordered_map<Node*, Node*>& parent, int target) {
        queue<Node*> q;
        q.push(root);
        
        Node* targetNode = NULL;
        
        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
            
            // Check if this is the target node
            if (curr->data == target) {
                targetNode = curr;
            }
            
            // If left child exists
            if (curr->left) {
                parent[curr->left] = curr;
                q.push(curr->left);
            }
            
            // If right child exists
            if (curr->right) {
                parent[curr->right] = curr;
                q.push(curr->right);
            }
        }
        
        return targetNode;
    }
    
    int minTime(Node* root, int target) {
        
        // Map to store parent of each node
        unordered_map<Node*, Node*> parent;
        
        // Step 2: Get target node
        Node* targetNode = buildParentMap(root, parent, target);
        
        // Step 3: BFS to simulate burning
        queue<Node*> q;
        unordered_map<Node*, bool> visited;
        
        q.push(targetNode);
        visited[targetNode] = true;
        
        int time = 0;
        
        while (!q.empty()) {
            int size = q.size();
            bool burned = false; // check if fire spreads in this second
            
            for (int i = 0; i < size; i++) {
                Node* curr = q.front();
                q.pop();
                
                // Check left child
                if (curr->left && !visited[curr->left]) {
                    burned = true;
                    visited[curr->left] = true;
                    q.push(curr->left);
                }
                
                // Check right child
                if (curr->right && !visited[curr->right]) {
                    burned = true;
                    visited[curr->right] = true;
                    q.push(curr->right);
                }
                
                // Check parent
                if (parent[curr] && !visited[parent[curr]]) {
                    burned = true;
                    visited[parent[curr]] = true;
                    q.push(parent[curr]);
                }
            }
            
            // If fire spread in this round, increase time
            if (burned) time++;
        }
        
        return time;
    }
};