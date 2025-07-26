class Solution {
  public:
    vector<int> findMajority(vector<int>& arr) {
        // Code here
        // Boyer-Moore Voting Algorithm extension for n/3 majority element
        int candidate1 = INT_MIN, candidate2 = INT_MIN;
        int count1 = 0, count2 = 0;

        // First pass: Find up to two candidates
        for (int num : arr) {
            if (num == candidate1) {
                count1++;
            }
            else if (num == candidate2) {
                count2++;
            }
            else if (count1 == 0) {
                candidate1 = num;
                count1 = 1;
            }
            else if (count2 == 0) {
                candidate2 = num;
                count2 = 1;
            }
            else {
                // Decrease both counts when num is not equal to any candidate
                count1--;
                count2--;
            }
        }

        // Second pass: Validate the candidates
        count1 = 0;
        count2 = 0;
        for (int num : arr) {
            if (num == candidate1) count1++;
            else if (num == candidate2) count2++;
        }

        // Prepare the result
        vector<int> result;
        int n = arr.size();
        if (count1 > n / 3) result.push_back(candidate1);
        if (count2 > n / 3) result.push_back(candidate2);

        sort(result.begin(), result.end());
        return result;
    }
};