class Solution {
  public:
    vector<int> topView(Node *root) {
        // This vector will store the final top view nodes
        vector<int> result;

        // If the tree is empty, return empty result
        if (!root) return result;

        // Map to store the first node encountered at each horizontal distance (hd)
        // Key = horizontal distance
        // Value = node data
        map<int, int> topNode;

        // Queue for level order traversal (BFS)
        // Each element contains: (node pointer, horizontal distance)
        queue<pair<Node*, int>> q;

        // Start BFS from root with horizontal distance = 0
        q.push({root, 0});

        // Process nodes level by level
        while (!q.empty()) {
            
            // Get the front node and its horizontal distance
            pair<Node*, int> current = q.front(); 
            q.pop();

            Node* node = current.first; // current tree node
            int hd = current.second;    // horizontal distance

            // If this horizontal distance is seen for the first time,
            // store the node because top view takes the first visible node
            if (topNode.find(hd) == topNode.end()) {
                topNode[hd] = node->data;
            }

            // If left child exists, push it into queue
            // Horizontal distance decreases by 1
            if (node->left) {
                q.push({node->left, hd - 1});
            }

            // If right child exists, push it into queue
            // Horizontal distance increases by 1
            if (node->right) {
                q.push({node->right, hd + 1});
            }
        }

        // Traverse the map in sorted order of horizontal distance
        // and store values in the result vector
        for (map<int, int>::iterator it = topNode.begin(); it != topNode.end(); ++it) {
            result.push_back(it->second); 
        }

        // Return the final top view
        return result;
    }
};