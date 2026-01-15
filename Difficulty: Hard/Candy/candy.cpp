class Solution {
  public:
    int minCandy(vector<int> &arr) {
        int n = arr.size();
        
        // Step 1: Every child gets at least one candy
        vector<int> candies(n, 1);

        // Step 2: Left to Right Pass
        // If current rating is higher than left neighbor,
        // give one more candy than left neighbor
        for (int i = 1; i < n; i++) {
            if (arr[i] > arr[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        // Step 3: Right to Left Pass
        // If current rating is higher than right neighbor,
        // ensure it has more candies than right neighbor
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] > arr[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }

        // Step 4: Sum all candies
        int totalCandies = 0;
        for (int c : candies) {
            totalCandies += c;
        }

        return totalCandies;
    }
};
