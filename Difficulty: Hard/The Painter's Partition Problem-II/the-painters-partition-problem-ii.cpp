class Solution {
public:

    // Function to check if we can paint all boards 
    // within 'maxTime' using at most k painters
    bool canPaint(vector<int>& arr, int k, long long maxTime) {
        
        long long currentSum = 0;   // Current painter's workload
        int painters = 1;           // At least 1 painter needed
        
        for (int i = 0; i < arr.size(); i++) {
            
            // If adding this board exceeds allowed maxTime
            if (currentSum + arr[i] > maxTime) {
                
                painters++;         // Assign new painter
                currentSum = arr[i]; // Start with current board
                
                // If painters exceed k → not possible
                if (painters > k)
                    return false;
            }
            else {
                currentSum += arr[i];  // Add board to current painter
            }
        }
        
        return true;  // Possible within k painters
    }

    int minTime(vector<int>& arr, int k) {
        
        int n = arr.size();
        
        // Edge Case: If painters >= boards
        // Then answer is max element (each painter gets one board)
        if (k >= n) {
            return *max_element(arr.begin(), arr.end());
        }
        
        long long low = *max_element(arr.begin(), arr.end());  // minimum time
        long long high = 0;  // maximum time
        
        // Calculate sum of array
        for (int i = 0; i < n; i++) {
            high += arr[i];
        }
        
        long long ans = high;  // store result
        
        while (low <= high) {
            
            long long mid = low + (high - low) / 2;  // prevent overflow
            
            // Check if possible with mid time
            if (canPaint(arr, k, mid)) {
                ans = mid;        // store answer
                high = mid - 1;   // try smaller time
            }
            else {
                low = mid + 1;    // increase time
            }
        }
        
        return (int)ans;
    }
};
