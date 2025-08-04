class Solution {
  public:
    // Function to check if vector 'b' is a subset of vector 'a'
    bool isSubset(vector<int> &a, vector<int> &b) {
        // Create a map to count occurrences of elements in vector 'a'
        map<int, int> mp;

        // Populate the map with frequencies of elements from vector 'a'
        for (auto it : a) {
            mp[it]++;  // Increase the count of the element 'it'
        }

        // Iterate through each element in vector 'b'
        for (auto it : b) {
            // If the element from 'b' is not present in 'a' or has been used up
            if (mp[it] == 0) {
                return false;  // 'b' is not a subset of 'a'
            }

            // Decrement the count for the element, as it is matched once
            mp[it]--;
        }

        // All elements in 'b' were found in 'a' with sufficient frequency
        return true;
    }
};
