class Solution {
  public:
    string firstNonRepeating(string &s) {
        
        // Array to store frequency of characters
        // Since only lowercase letters, size 26 is enough
        vector<int> freq(26, 0);
        
        // Queue to maintain order of characters
        queue<char> q;
        
        // Result string
        string result = "";
        
        // Traverse the string
        for(char ch : s) {
            
            // Step 1: Increase frequency
            freq[ch - 'a']++;
            
            // Step 2: Push character into queue
            q.push(ch);
            
            // Step 3: Remove characters from front 
            // if they are repeating (freq > 1)
            while(!q.empty() && freq[q.front() - 'a'] > 1) {
                q.pop();
            }
            
            // Step 4: If queue empty, no non-repeating character
            if(q.empty())
                result += '#';
            else
                result += q.front();
        }
        
        return result;
    }
};
