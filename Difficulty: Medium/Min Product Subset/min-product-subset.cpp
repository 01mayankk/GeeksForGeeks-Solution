class Solution {
  public:
      int minProd(vector<int>& arr) {
          int n = arr.size();

          // If there's only one element, it forms the only possible subset
          if (n == 1) return arr[0];

          int max_neg = -100; // Stores the max negative number (closest to 0)
          int min_pos = 100;  // Stores the min positive number
          int count_neg = 0;  // Tracks the number of negative elements
          int count_zero = 0; // Tracks the number of zero elements
          long long prod = 1; // Product of all non-zero elements

          for (int i = 0; i < n; i++) {
              if (arr[i] == 0) {
                  count_zero++;
                  continue;
              }
              if (arr[i] < 0) {
                  count_neg++;
                  max_neg = max(max_neg, arr[i]);
              }
              if (arr[i] > 0) {
                  min_pos = min(min_pos, arr[i]);
              }

              prod *= arr[i];
          }

          // If the array contains only zeros, or strictly positive numbers and zeros
          if (count_zero == n || (count_neg == 0 && count_zero > 0)) {
              return 0;
          }

          // If there are no negative numbers and no zeros, 
          // the minimum subset product is the smallest positive element
          if (count_neg == 0) {
              return min_pos;
          }

          // If there are an even number of negative numbers, the overall product 
          // is positive. We exclude the largest negative number (closest to 0)
          // to make the final product negative and as small as possible.
          if (count_neg % 2 == 0) {
              prod /= max_neg;
          }

          return prod;
      }
  };