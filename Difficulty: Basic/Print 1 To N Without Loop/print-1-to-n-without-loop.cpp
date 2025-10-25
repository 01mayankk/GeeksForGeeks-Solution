class Solution {
  public:
    // Function to print numbers from 1 to n using recursion
    void printNos(int n) {
        // Base case: stop when n becomes 0
        if (n == 0)
            return;
        
        // Recursive call for previous number first
        printNos(n - 1);
        
        // Print current number after returning from recursion
        cout << n << " ";
    }
};
