class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {

        vector<int> police, thieves;

        // Step 1: Store positions of police and thieves
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == 'P')
                police.push_back(i);
            else
                thieves.push_back(i);
        }

        int i = 0, j = 0;   // pointers for police and thieves
        int caught = 0;

        // Step 2: Match police with thieves using two pointers
        while (i < police.size() && j < thieves.size()) {

            // If distance between police and thief is within k
            if (abs(police[i] - thieves[j]) <= k) {
                caught++;   // thief caught
                i++;        // move to next police
                j++;        // move to next thief
            }
            // Thief is too far left, move to next thief
            else if (thieves[j] < police[i]) {
                j++;
            }
            // Police is too far left, move to next police
            else {
                i++;
            }
        }

        return caught;
    }
};
