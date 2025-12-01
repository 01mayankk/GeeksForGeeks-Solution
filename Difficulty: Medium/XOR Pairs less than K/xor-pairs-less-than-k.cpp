class Solution {
public:
    // Trie Node: stores 2 children (bit 0 and bit 1)
    // and count of numbers passing through this node
    struct Node {
        Node* bit[2];
        int cnt;
        Node() {
            bit[0] = bit[1] = nullptr;
            cnt = 0;
        }
    };
    
    Node* root = new Node();  // Root of binary trie
    
    // Insert a number x in binary form into trie
    void insert(int x) {
        Node* cur = root;
        
        // traverse bits from MSB (15) to LSB (0)
        for(int b = 15; b >= 0; b--) {
            int bitVal = (x >> b) & 1;       // extract b-th bit
            
            // create node if not present
            if(!cur->bit[bitVal]) 
                cur->bit[bitVal] = new Node();
            
            cur = cur->bit[bitVal];          // move to next bit branch
            cur->cnt++;                      // increment count passing through this node
        }
    }
    
    // Count how many numbers already in trie satisfy:
    // (x XOR y) < k
    int countLessThanK(int x, int k) {
        Node* cur = root;
        int ans = 0;
        
        // traverse bits from MSB to LSB
        for(int b = 15; b >= 0; b--) {
            if(!cur) break;  // no further path → stop
            
            int xb = (x >> b) & 1;   // bit of x
            int kb = (k >> b) & 1;   // bit of k
            
            /*
                Case 1: If k's bit = 1
                ----------------------------------
                Then XOR at this bit must be 0 to stay smaller → allowed

                That means y's bit must = xb
                → We can add whole subtree of numbers with that bit!
            */
            if(kb == 1) {
                // Add all numbers in matching bit branch
                if(cur->bit[xb]) ans += cur->bit[xb]->cnt;
                
                // Continue comparing in (xb^1) branch → where XOR becomes 1,
                // but lower bits may still keep result < k
                cur = cur->bit[xb ^ 1];
            }
            else {
                /*
                    Case 2: k's bit = 0
                    ----------------------------------
                    Then XOR at this bit must also be 0

                    So we MUST go to branch having same bit as x
                    No addition — only continue searching
                */
                cur = cur->bit[xb];
            }
        }
        
        return ans;
    }
    
    // Main function to count XOR pairs < k
    int cntPairs(vector<int>& arr, int k) {
        int result = 0;
        
        for(int x : arr) {
            result += countLessThanK(x, k);  // count valid previous numbers for x
            insert(x);                       // insert x into trie
        }
        
        return result;
    }
};
