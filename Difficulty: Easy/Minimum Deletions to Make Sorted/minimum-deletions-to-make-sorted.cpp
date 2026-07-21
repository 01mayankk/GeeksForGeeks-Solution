class Solution {
  public:
    int minDeletions(std::vector<int>& arr) {
        int n = arr.size();
        std::vector<int> lis;

        for (int x : arr) {
            // Find the first element in 'lis' that is greater than or equal to x
            auto it = std::lower_bound(lis.begin(), lis.end(), x);
            
            // If x is larger than all elements in lis, extend the LIS
            if (it == lis.end()) {
                lis.push_back(x);
            } else {
                // Replace the existing element to keep the active subsequence tails as small as possible
                *it = x;
            }
        }

        // Minimum deletions needed = total length - length of Longest Increasing Subsequence
        return n - lis.size();
    }
};