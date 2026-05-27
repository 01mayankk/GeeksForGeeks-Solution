/* Structure of binary tree node
class Node{
public:
    int data;
    Node* left, right;

    Node(int item)
    {
        data = item;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
  
    // Helper function for DFS traversal
    void solve(Node* root, int hd, map<int, int>& mp)
    {
        // Base case
        if(root == NULL)
        {
            return;
        }
        
        // Store sum for current vertical line
        mp[hd] += root->data;
        
        // Left child -> horizontal distance decreases
        solve(root->left, hd - 1, mp);
        
        // Right child -> horizontal distance increases
        solve(root->right, hd + 1, mp);
    }
  
    vector<int> verticalSum(Node* root) {
        
        // Map:
        // key   -> horizontal distance
        // value -> sum of nodes at that distance
        map<int, int> mp;
        
        // Start traversal from root
        // Root horizontal distance = 0
        solve(root, 0, mp);
        
        vector<int> ans;
        
        // Map automatically stores keys in sorted order
        // So we get left-most vertical line first
        for(auto &it : mp)
        {
            ans.push_back(it.second);
        }
        
        return ans;
    }
};