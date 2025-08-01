class Solution {
  public:
    int countBalanced(vector<string>& arr) {
        // This vector will store the difference between vowel and consonant count for each word
        vector<int> sample;

        // This map will store the prefix sum frequency of vowel-consonant difference
        unordered_map<int, int> omap;

        // Loop through each word in the array
        for(int i = 0; i < arr.size(); i++) {
            string temp = arr[i];
            int cntV = 0; // vowel count
            int cntC = 0; // consonant count

            // Count vowels and consonants in the current string
            for(int j = 0; j < temp.length(); j++) {
                if(temp.at(j) == 'a' || temp.at(j) == 'e' || temp.at(j) == 'i' || temp.at(j) == 'o' || temp.at(j) == 'u') {
                    cntV++;
                } else {
                    cntC++;
                }
            }

            // Store the difference between vowel and consonant count
            sample.push_back(cntV - cntC);
        }

        int count = 0;  // final count of balanced subarrays
        int total = 0;  // prefix sum of the differences

        // Initialize the map with 0 prefix sum (neutral difference)
        omap[0] = 1;

        // Iterate through the prefix sum array
        for(int i = 0; i < sample.size(); i++) {
            total += sample[i]; // update the running prefix sum

            // If this sum has been seen before, it means there exists a subarray
            // which is balanced (equal vowels and consonants)
            if(omap.find(total) != omap.end()) {
                count += omap[total];
            }

            // Increment the frequency of this prefix sum
            omap[total]++;
        }

        // Return total number of balanced subarrays
        return count;
    }
};
