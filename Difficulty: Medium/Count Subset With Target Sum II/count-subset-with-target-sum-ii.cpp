class Solution {
  public:
    
    // Helper function to generate all subset sums of a subarray
    void generateSubsets(int idx, int end,
                         vector<int> &arr,
                         long long currSum,
                         vector<long long> &sums) {
        
        // If we have processed the subarray
        if (idx == end) {
            sums.push_back(currSum);
            return;
        }

        // Choice 1: Do NOT include current element
        generateSubsets(idx + 1, end, arr, currSum, sums);

        // Choice 2: Include current element
        generateSubsets(idx + 1, end, arr, currSum + arr[idx], sums);
    }
    
    int countSubset(vector<int> &arr, int k) {
        
        int n = arr.size();
        int mid = n / 2;

        // Vectors to store subset sums of both halves
        vector<long long> leftSums, rightSums;

        // Generate subset sums for left half [0 ... mid-1]
        generateSubsets(0, mid, arr, 0, leftSums);

        // Generate subset sums for right half [mid ... n-1]
        generateSubsets(mid, n, arr, 0, rightSums);

        // Sort right sums for binary search
        sort(rightSums.begin(), rightSums.end());

        long long count = 0;

        // For each sum in left half,
        // find number of right sums such that:
        // leftSum + rightSum = k
        for (long long left : leftSums) {
            long long need = k - left;

            // Count occurrences using binary search
            auto low = lower_bound(rightSums.begin(), rightSums.end(), need);
            auto high = upper_bound(rightSums.begin(), rightSums.end(), need);

            count += (high - low);
        }

        return (int)count;
    }
};
