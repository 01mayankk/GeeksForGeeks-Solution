class Solution {
public:
    int find(vector<int>& arr) {
        // x represents the minimum value required after the current element's operation.
        // Initially, to ensure it never becomes negative, it must be at least 0 at the end.
        long long x = 0; 
        
        // Process the array in reverse order to find the required starting value.
        for (int i = arr.size() - 1; i >= 0; i--) {
            // The formula for the transition is: x_new = 2 * x_old - arr[i]
            // Rewriting to find x_old: x_old = ceil((x_new + arr[i]) / 2)
            // In integer arithmetic, ceil(a / 2) can be calculated as (a + 1) / 2
            x = (x + arr[i] + 1) / 2;
        }
        
        return x;
    }
};