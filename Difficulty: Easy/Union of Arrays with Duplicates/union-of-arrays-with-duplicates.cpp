class Solution {
  public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        // code here
        set<int>sorted(a.begin(), a.end());
        sorted.insert(b.begin(), b.end());
        vector<int>result(sorted.begin(), sorted.end());
        
        return result;
    }
};