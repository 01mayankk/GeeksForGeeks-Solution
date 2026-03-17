/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    
    int moves = 0; // to store total number of moves
    
    // Helper function: returns net balance of candies
    int dfs(Node* root) {
        // Base case
        if (root == NULL) return 0;
        
        // Get balance from left subtree
        int left = dfs(root->left);
        
        // Get balance from right subtree
        int right = dfs(root->right);
        
        // Moves needed = candies moved from left + right
        // Absolute because movement can be in either direction
        moves += abs(left) + abs(right);
        
        // Current node balance:
        // (current candies + left + right - 1 required)
        int balance = root->data + left + right - 1;
        
        return balance;
    }
    
    int distCandy(Node* root) {
        dfs(root);
        return moves;
    }
};