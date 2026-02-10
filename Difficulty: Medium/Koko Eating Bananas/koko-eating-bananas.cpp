class Solution {
  public:
    int kokoEat(vector<int>& arr, int k) {
        // Minimum possible eating speed (at least 1 banana/hour)
        int minSpeed = 1;
        
        // Maximum possible eating speed
        // Koko can finish a pile in 1 hour if she eats at max pile size
        int maxSpeed = *max_element(arr.begin(), arr.end());
        
        // Binary search on eating speed
        while (minSpeed < maxSpeed) {
            
            // Mid speed to test
            // Prevents overflow
            int midSpeed = minSpeed + (maxSpeed - minSpeed) / 2;
            
            // Total hours needed at this speed
            int hour = 0;
            
            // Calculate hours required for each pile
            for (auto& elem : arr) {
                // Ceiling division:
                // number of hours = ceil(elem / midSpeed)
                hour += (elem + midSpeed - 1) / midSpeed;
            }
            
            // If Koko can finish all bananas within k hours
            if (hour <= k) {
                // Try to reduce the eating speed
                maxSpeed = midSpeed;
            } 
            else {
                // Speed is too slow → increase speed
                minSpeed = midSpeed + 1;
            }
        }
        
        // minSpeed now holds the minimum valid eating speed
        return minSpeed;
    }
};
