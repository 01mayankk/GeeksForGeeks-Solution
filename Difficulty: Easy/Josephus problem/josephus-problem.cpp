class Solution {
  public:
    
    int josephus(int n, int k) {
        // Base case:
        // If only one person is there, he survives (0-based index)
        if (n == 1)
            return 1;  // 1-based index

        // Recursive step:
        // josephus(n-1, k) gives survivor position in (n-1) people (1-based)
        // Convert it to 0-based, apply formula, then convert back to 1-based
        int prev = josephus(n - 1, k);   // survivor in smaller problem (1-based)
        
        // Convert to 0-based, apply recurrence, then convert back
        return (prev + k - 1) % n + 1;
    }
};
