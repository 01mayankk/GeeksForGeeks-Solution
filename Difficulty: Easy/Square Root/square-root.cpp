class Solution {
  public:
    int floorSqrt(int n) {
        // code here
        return floor(sqrt(n));
    }
};


// class Solution {
//   public:
//     int floorSqrt(int n) {
//         // Base cases:
//         // If n is 0 or 1, the square root is the number itself
//         if (n == 0 || n == 1)
//             return n;

//         // Initialize binary search boundaries
//         int low = 1, high = n;
//         int ans = 1;  // To store the floor value of sqrt(n)

//         // Perform binary search
//         while (low <= high) {
//             // Use long long to avoid overflow when squaring mid
//             long long mid = (low + high) / 2;

//             // If mid*mid == n, perfect square found
//             if (mid * mid == n)
//                 return mid;

//             // If mid*mid < n, move to the right half
//             // but store mid as a potential floor value
//             else if (mid * mid < n) {
//                 ans = mid;       // mid could be the floor of sqrt(n)
//                 low = mid + 1;   // search in higher half
//             }

//             // If mid*mid > n, move to the left half
//             else {
//                 high = mid - 1;
//             }
//         }

//         // Return the floor value (largest mid such that mid*mid <= n)
//         return ans;
//     }
// };
