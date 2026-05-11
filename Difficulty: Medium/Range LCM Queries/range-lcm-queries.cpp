class Solution {
  public:
  
    // Segment tree array
    vector<long long> seg;

    // ---------------------------------------------------
    // Function to find GCD using Euclidean Algorithm
    // ---------------------------------------------------
    long long gcd(long long a, long long b) {
        
        // Continue until remainder becomes 0
        while(b) {
            long long temp = b;
            b = a % b;
            a = temp;
        }
        
        return a;
    }
    
    // ---------------------------------------------------
    // Function to calculate LCM
    // Formula:
    // LCM(a, b) = (a / GCD(a, b)) * b
    // ---------------------------------------------------
    long long lcm(long long a, long long b) {
        return (a / gcd(a, b)) * b;
    }
    
    // ---------------------------------------------------
    // Build Segment Tree
    // Each node stores LCM of its segment
    // ---------------------------------------------------
    void build(int idx, int low, int high, vector<int> &arr) {
        
        // Base Case:
        // Leaf node contains single element
        if(low == high) {
            seg[idx] = arr[low];
            return;
        }
        
        // Find middle index
        int mid = (low + high) / 2;
        
        // Build left child
        build(2 * idx + 1, low, mid, arr);
        
        // Build right child
        build(2 * idx + 2, mid + 1, high, arr);
        
        // Current node stores LCM of left and right child
        seg[idx] = lcm(seg[2 * idx + 1], seg[2 * idx + 2]);
    }
    
    // ---------------------------------------------------
    // Update Query
    // Update value at given index
    // ---------------------------------------------------
    void update(int idx, int low, int high, int pos, int val) {
        
        // Reached the target index
        if(low == high) {
            seg[idx] = val;
            return;
        }
        
        int mid = (low + high) / 2;
        
        // If target index lies in left half
        if(pos <= mid)
            update(2 * idx + 1, low, mid, pos, val);
        
        // Else go to right half
        else
            update(2 * idx + 2, mid + 1, high, pos, val);
        
        // Recalculate current node after update
        seg[idx] = lcm(seg[2 * idx + 1], seg[2 * idx + 2]);
    }
    
    // ---------------------------------------------------
    // Range Query
    // Returns LCM in range [l, r]
    // ---------------------------------------------------
    long long query(int idx, int low, int high, int l, int r) {
        
        // No Overlap
        // Current segment completely outside query range
        if(high < l || low > r)
            return 1; // Identity element for LCM
        
        // Complete Overlap
        // Current segment completely inside query range
        if(low >= l && high <= r)
            return seg[idx];
        
        // Partial Overlap
        int mid = (low + high) / 2;
        
        // Query left subtree
        long long left = query(2 * idx + 1, low, mid, l, r);
        
        // Query right subtree
        long long right = query(2 * idx + 2, mid + 1, high, l, r);
        
        // Return combined LCM
        return lcm(left, right);
    }
    
    // ---------------------------------------------------
    // Main Function
    // Processes all queries
    // ---------------------------------------------------
    vector<long long> RangeLCMQuery(vector<int> &arr,
                                    vector<vector<int>> &queries) {
        
        int n = arr.size();
        
        // Resize segment tree
        seg.resize(4 * n);
        
        // Build segment tree
        build(0, 0, n - 1, arr);
        
        // Stores answers of Type-2 queries
        vector<long long> ans;
        
        // Process all queries one by one
        for(auto &q : queries) {
            
            // ------------------------------------------------
            // Type 1 Query -> Update
            // Format: [1, index, value]
            // ------------------------------------------------
            if(q[0] == 1) {
                
                int index = q[1];
                int value = q[2];
                
                // Update segment tree
                update(0, 0, n - 1, index, value);
            }
            
            // ------------------------------------------------
            // Type 2 Query -> Range LCM Query
            // Format: [2, L, R]
            // ------------------------------------------------
            else {
                
                int l = q[1];
                int r = q[2];
                
                // Find LCM in range and store answer
                ans.push_back(query(0, 0, n - 1, l, r));
            }
        }
        
        // Return all Type-2 query answers
        return ans;
    }
};