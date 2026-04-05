class Solution {
public:
    // ─── Huffman Tree Node ───────────────────────────────────────────────────
    struct Node {
        int freq;    // frequency (or combined frequency for internal nodes)
        int idx;     // original input index; min of children for internal nodes
        Node* left;
        Node* right;
        Node(int f, int i = -1) : freq(f), idx(i), left(nullptr), right(nullptr) {}
    };

    // ─── Min-Heap Comparator ─────────────────────────────────────────────────
    // Primary   : smaller freq  → higher priority (classic Huffman greedy)
    // Tie-break : smaller idx   → higher priority (first-seen goes LEFT)
    struct Compare {
        bool operator()(Node* a, Node* b) {
            if (a->freq != b->freq) return a->freq > b->freq;
            return a->idx > b->idx;
        }
    };

    // ─── Preorder Traversal ──────────────────────────────────────────────────
    // Recurse left (append '0') then right (append '1')
    // Only LEAF nodes represent actual characters → push their code
    void preorder(Node* root, string code, vector<string>& result) {
        if (!root) return;

        // Leaf: both children null → real character, store its code
        if (!root->left && !root->right) {
            result.push_back(code);
            return;
        }

        preorder(root->left,  code + "0", result);  // left  edge → '0'
        preorder(root->right, code + "1", result);  // right edge → '1'
    }

    // ─── Main ────────────────────────────────────────────────────────────────
    vector<string> huffmanCodes(string &s, vector<int> f) {
        int n = s.size();

        // Step 1: Seed the min-heap with one leaf node per character
        priority_queue<Node*, vector<Node*>, Compare> minHeap;
        for (int i = 0; i < n; i++)
            minHeap.push(new Node(f[i], i));

        // Step 2: Build Huffman tree — keep merging the two cheapest nodes
        while (minHeap.size() > 1) {
            Node* left  = minHeap.top(); minHeap.pop();   // lowest freq
            Node* right = minHeap.top(); minHeap.pop();   // second lowest freq

            // Merged internal node:
            //   freq = sum of children (used for future comparisons)
            //   idx  = min of children (preserves tie-breaking for future merges)
            Node* merged = new Node(left->freq + right->freq,
                                    min(left->idx, right->idx));
            merged->left  = left;
            merged->right = right;

            minHeap.push(merged);
        }

        // Step 3: Last node standing = root of the complete Huffman tree
        Node* root = minHeap.top();

        vector<string> ans;

        // Edge case: single character → tree has no edges, so no 0/1 is ever
        // appended during traversal; assign "0" by convention
        if (!root->left && !root->right) {
            ans.push_back("0");
            return ans;
        }

        // Step 4: Collect codes in preorder (left-before-right) traversal order
        // Root starts with empty prefix; each tree edge appends a bit
        preorder(root, "", ans);
        return ans;
    }
};