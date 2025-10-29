class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        // code here
        vector<int> c = a;
        c.insert(c.end(), b.begin(), b.end()); // merge both
        sort(c.begin(), c.end());
        return c[k - 1];

    }
};