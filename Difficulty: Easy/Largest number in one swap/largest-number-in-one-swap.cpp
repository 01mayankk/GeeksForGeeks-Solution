class Solution {
  public:
    string largestSwap(string &s) {
        
        int n = s.length();
        
        // Store the last index of each digit (0-9)
        vector<int> last(10, -1);
        
        // Fill the last occurrence of every digit
        for(int i = 0; i < n; i++)
        {
            last[s[i] - '0'] = i;
        }
        
        // Traverse the string
        for(int i = 0; i < n; i++)
        {
            int currentDigit = s[i] - '0';
            
            // Check for a larger digit from 9 down to currentDigit+1
            for(int d = 9; d > currentDigit; d--)
            {
                // If a larger digit exists later in the string
                if(last[d] > i)
                {
                    // Swap current digit with that larger digit
                    swap(s[i], s[last[d]]);
                    
                    // Only one swap allowed → return result
                    return s;
                }
            }
        }
        
        // If no beneficial swap found
        return s;
    }
};