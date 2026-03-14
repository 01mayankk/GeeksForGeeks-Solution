/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    vector<vector<int>> verticalOrder(Node *root) {
        
        // Final answer
        vector<vector<int>> result;
        
        // Edge case: empty tree
        if(root == NULL)
            return result;

        // Map to store nodes for each horizontal distance
        // key = horizontal distance
        // value = list of nodes in that vertical line
        map<int, vector<int>> mp;

        // Queue for BFS
        // pair<Node*, horizontal distance>
        queue<pair<Node*, int>> q;

        // Start BFS with root at horizontal distance 0
        q.push({root, 0});

        while(!q.empty()) {
            
            // Get front element
            auto current = q.front();
            q.pop();

            Node* node = current.first;
            int hd = current.second;

            // Store node value in the map
            mp[hd].push_back(node->data);

            // If left child exists
            if(node->left) {
                // Horizontal distance decreases
                q.push({node->left, hd - 1});
            }

            // If right child exists
            if(node->right) {
                // Horizontal distance increases
                q.push({node->right, hd + 1});
            }
        }

        // Traverse the map (automatically sorted by HD)
        for(auto it : mp) {
            result.push_back(it.second);
        }

        return result;
    }
};
