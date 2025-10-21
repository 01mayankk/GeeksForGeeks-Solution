
class Solution {
public:
    vector<int> topKFreq(vector<int> &arr, int k) {
        // Step 1: Count the frequency of each element
        unordered_map<int, int> freqMap;
        for (int num : arr) {
            freqMap[num]++;
        }

        // Step 2: Move the map contents to a vector of pairs for sorting
        vector<pair<int, int>> freqVec;
        for (auto& pair : freqMap) {
            // Pushing {frequency, number} to make sorting easier
            freqVec.push_back({pair.second, pair.first});
        }

        // Step 3: Sort the vector with a custom comparator
        // - Sort by frequency in descending order (a.first > b.first)
        // - If frequencies are the same, sort by number in descending order (a.second > b.second)
        sort(freqVec.begin(), freqVec.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first != b.first) {
                return a.first > b.first; // Higher frequency first
            }
            return a.second > b.second; // Larger number first for ties
        });

        // Step 4: Extract the top k elements
        vector<int> result;
        for (int i = 0; i < k; ++i) {
            result.push_back(freqVec[i].second); // .second is the number
        }

        return result;
    }
};