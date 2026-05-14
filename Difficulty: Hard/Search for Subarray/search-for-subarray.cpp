class Solution {
  public:
    
    // Function to build the LPS (Longest Prefix Suffix) array
    // LPS[i] stores the length of the longest proper prefix
    // which is also a suffix for substring pattern[0...i]
    vector<int> buildLPS(vector<int>& pattern) {
        
        // Length of pattern array
        int m = pattern.size();
        
        // Initialize LPS array with 0
        vector<int> lps(m, 0);
        
        // Length of previous longest prefix suffix
        int len = 0;
        
        // Start from index 1 because lps[0] is always 0
        int i = 1;
        
        // Build LPS array
        while(i < m) {
            
            // If current elements match
            if(pattern[i] == pattern[len]) {
                
                // Increase prefix length
                len++;
                
                // Store length in LPS array
                lps[i] = len;
                
                // Move to next index
                i++;
            }
            else {
                
                // Mismatch occurs
                
                // Try smaller possible prefix
                if(len != 0) {
                    len = lps[len - 1];
                }
                else {
                    // No prefix suffix exists
                    lps[i] = 0;
                    i++;
                }
            }
        }
        
        // Return completed LPS array
        return lps;
    }
    
    // Function to find all occurrences of b[] in a[]
    vector<int> search(vector<int> &a, vector<int> &b) {
        
        // Vector to store all starting indices
        vector<int> ans;
        
        // Size of main array
        int n = a.size();
        
        // Size of pattern array
        int m = b.size();
        
        // Build LPS array for pattern b[]
        vector<int> lps = buildLPS(b);
        
        // Pointer for main array a[]
        int i = 0;
        
        // Pointer for pattern array b[]
        int j = 0;
        
        // Perform KMP pattern matching
        while(i < n) {
            
            // If current elements match
            if(a[i] == b[j]) {
                i++;
                j++;
            }
            
            // If full pattern is matched
            if(j == m) {
                
                // Store starting index of match
                ans.push_back(i - j);
                
                // Continue searching for next possible match
                j = lps[j - 1];
            }
            
            // If mismatch occurs after some matches
            else if(i < n && a[i] != b[j]) {
                
                // Move pattern pointer using LPS array
                if(j != 0) {
                    j = lps[j - 1];
                }
                else {
                    // If no match yet, move main array pointer
                    i++;
                }
            }
        }
        
        // Return all matching starting indices
        return ans;
    }
};