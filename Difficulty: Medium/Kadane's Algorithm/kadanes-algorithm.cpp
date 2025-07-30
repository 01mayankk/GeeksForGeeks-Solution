class Solution {
  public:
    int maxSubarraySum(vector<int>& nums) {
    int maxSum = nums[0], curr = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        curr = max(nums[i], curr + nums[i]);
        maxSum = max(maxSum, curr);
    }

    return maxSum;
}

};