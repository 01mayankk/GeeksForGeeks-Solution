class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
    // Create a set and insert all elements from a
    set<int> sorted(a.begin(), a.end());
    
    // Insert all elements from b into the same set
    sorted.insert(b.begin(), b.end());
    
    // Copy all unique sorted elements from set to vector
    vector<int> arr(sorted.begin(), sorted.end());
    
    // Return the result
    return arr;
    }
};