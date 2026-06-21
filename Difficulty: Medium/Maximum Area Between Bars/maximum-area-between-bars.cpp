class Solution {
public:
    int maxArea(vector<int> &height) {

        int n = height.size();

        // Two pointers at the extreme ends
        int left = 0;
        int right = n - 1;

        // Stores the maximum area found so far
        long long maxArea = 0;

        // Continue until both pointers meet
        while (left < right) {

            // Number of bars lying between the selected bars
            int width = right - left - 1;

            // Height of rectangle is limited by the shorter bar
            int minHeight = min(height[left], height[right]);

            // Calculate current area
            long long area = 1LL * minHeight * width;

            // Update maximum area if current area is larger
            maxArea = max(maxArea, area);

            // Move the pointer with smaller height
            // because increasing the shorter height may
            // give a larger area in future
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        // Return the maximum rectangular area
        return (int)maxArea;
    }
};