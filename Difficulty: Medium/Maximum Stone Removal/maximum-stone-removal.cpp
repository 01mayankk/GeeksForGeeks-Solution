class Solution {
public:
    // Disjoint Set Union (Union-Find) with path compression + union by size
    vector<int> parent, sizeArr;

    // Find the representative (root) of a node with path compression
    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);   // path compression
    }

    // Union two sets by size (smaller attaches to larger)
    void unionSet(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) return;     // already in same set

        // attach the smaller tree to the larger tree
        if (sizeArr[a] < sizeArr[b]) 
            swap(a, b);

        parent[b] = a;
        sizeArr[a] += sizeArr[b];
    }

    int maxRemove(vector<vector<int>>& stones) {
        int n = stones.size();

        // Coordinates range: 0 ≤ xi, yi ≤ 10^4
        // We map:
        //    row nodes    -> 0 to 10000
        //    column nodes -> 10001 to 20000
        // This avoids collision between row indices and column indices
        int MAX = 20005;

        parent.resize(MAX);
        sizeArr.resize(MAX, 1);

        // Initially, every node is its own parent (self-loop)
        for (int i = 0; i < MAX; i++)
            parent[i] = i;

        // Step 1: Union row and column for each stone
        // A stone at (x, y) connects row x with column (y + 10001)
        for (auto &s : stones) {
            int row = s[0];
            int col = s[1] + 10001;    // Shift column index to avoid collision
            unionSet(row, col);
        }

        // Step 2: Count how many unique connected components exist
        // Only consider the components that contain at least one stone
        unordered_set<int> components;
        for (auto &s : stones) {
            int root = find(s[0]);  // find representative of its row node
            components.insert(root);
        }

        // If a component has k stones, we can remove k - 1 of them.
        // So total removable stones = total stones - number of components
        return n - components.size();
    }
};
