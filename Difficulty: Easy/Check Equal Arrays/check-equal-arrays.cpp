class Solution {
  public:
    // Function to check if two arrays contain the same elements with the same frequency
    bool checkEqual(vector<int>& a, vector<int>& b) {
        // If sizes are not equal, they can't be equal
        if (a.size() != b.size()) return false;

        // Frequency map for counting elements in 'a'
        unordered_map<int, int> freq;

        // Count frequency of each element in 'a'
        for (int num : a) {
            freq[num]++;
        }

        // Decrease frequency for each element in 'b'
        for (int num : b) {
            if (freq.find(num) == freq.end() || freq[num] == 0) {
                return false; // Element missing or overused
            }
            freq[num]--;
        }

        // No need to check remaining map entries — counts already match due to equal sizes
        return true;
    }
};
