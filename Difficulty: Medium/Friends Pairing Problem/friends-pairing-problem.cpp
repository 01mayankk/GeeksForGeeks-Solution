class Solution {
public:
    int countFriendsPairings(int n) {
        // Base cases for 1 and 2 friends
        if (n <= 2) {
            return n;
        }
        
        // Variables to store the results of subproblems
        // a represents f(n-2) and b represents f(n-1)
        int a = 1; 
        int b = 2; 
        int c = 0; 
        
        // Calculate the number of ways for i friends
        for (int i = 3; i <= n; i++) {
            // i-th friend can remain single: b ways
            // i-th friend can pair with any of the (i-1) friends: (i-1) * a ways
            c = b + (i - 1) * a;
            
            // Update a and b for the next iteration
            a = b;
            b = c;
        }
        
        return c;
    }
};