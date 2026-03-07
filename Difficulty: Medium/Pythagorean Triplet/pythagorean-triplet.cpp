class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        
        // Maximum possible value of arr[i] according to constraints
        const int MAX = 1000;
        
        // Frequency array to store how many times each number appears
        vector<int> freq(MAX + 1, 0);
        
        // Count occurrences of every number in the array
        for(int x : arr)
            freq[x]++;
        
        // Try every possible pair (a, b)
        for(int a = 1; a <= MAX; a++) {
            
            // If 'a' does not exist in the array, skip it
            if(freq[a] == 0) continue;
            
            for(int b = a; b <= MAX; b++) {
                
                // If 'b' does not exist in the array, skip it
                if(freq[b] == 0) continue;
                
                // Calculate a² + b²
                int c_sq = a*a + b*b;
                
                // Find c = sqrt(a² + b²)
                int c = sqrt(c_sq);
                
                // Check if c² exactly equals a² + b²
                // and if c is within allowed range and exists in array
                if(c*c == c_sq && c <= MAX && freq[c] > 0) {
                    
                    // Ensure indices are different when values are same
                    
                    // Case 1: a = b = c → need at least 3 occurrences
                    if(a == b && b == c) {
                        if(freq[a] >= 3) return true;
                    }
                    
                    // Case 2: a = b but different from c → need at least 2 occurrences of a
                    else if(a == b) {
                        if(freq[a] >= 2) return true;
                    }
                    
                    // Case 3: b = c but different from a → need at least 2 occurrences of b
                    else if(b == c) {
                        if(freq[b] >= 2) return true;
                    }
                    
                    // Case 4: all numbers different
                    else {
                        return true;
                    }
                }
            }
        }
        
        // If no Pythagorean triplet is found
        return false;
    }
};