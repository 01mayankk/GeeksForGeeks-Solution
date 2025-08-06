class Solution {
  public:
    int romanToDecimal(string &s) {
        // Create a hashmap to store Roman numeral characters and their corresponding integer values
        unordered_map<char, int> value = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int ans = 0; // Initialize result variable to store final decimal value

        // Traverse the Roman numeral string from left to right
        for (int i = 0; i < s.size(); ++i) {
            int curr = value[s[i]]; // Get the integer value of the current Roman character
            int next = 0; // Initialize the next value to 0

            // If the next character exists, get its value
            if(i < s.size() - 1){
                next = value[s[i + 1]];
            }

            // If current value is less than next, it’s a subtractive pair (e.g., IV = 4, IX = 9)
            if (curr < next)
                ans -= curr; // Subtract current value from result
            else
                ans += curr; // Otherwise, add current value to result
        }

        // Return the computed decimal value
        return ans;
    }
};
