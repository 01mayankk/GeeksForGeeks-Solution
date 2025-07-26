#include<bits/stdc++.h>
class Solution {
  public:
    // Function to find the maximum triplet sum in the array.
    int maxTripletSum(vector<int> &arr) {
        // Complete the function
        sort(arr.begin(), arr.end());
        int sum = 0;
        for(int i = arr.size() - 1; i >= arr.size() - 3; i--)
        {
            sum += arr[i];
        }
        
        return sum;
    }
};