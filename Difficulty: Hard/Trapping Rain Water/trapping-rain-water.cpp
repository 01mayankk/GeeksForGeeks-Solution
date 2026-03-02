class Solution {
public:
    int maxWater(vector<int> &arr) {
        
        stack<int> st;          // Stack to store indices of bars
        int water = 0;          // Total trapped water
        int n = arr.size();
        
        for(int i = 0; i < n; i++) {
            
            // Process only when current height is greater than stack top height
            // This means we have found a right boundary
            while(!st.empty() && arr[i] > arr[st.top()]) {
                
                int bottom = st.top();   // Index of bottom bar
                st.pop();                // Remove bottom
                
                // If stack becomes empty, no left boundary exists
                if(st.empty()) break;
                
                int left = st.top();     // Index of left boundary
                
                // Width between left and right boundary
                // Subtract 1 because boundaries don't hold water
                int width = i - left - 1;
                
                // Height of trapped water
                // Minimum of left & right boundary minus bottom height
                int height = min(arr[left], arr[i]) - arr[bottom];
                
                // Add trapped water
                water += width * height;
            }
            
            // Push current index as potential boundary
            st.push(i);
        }
        
        return water;   // Return total trapped water
    }
};