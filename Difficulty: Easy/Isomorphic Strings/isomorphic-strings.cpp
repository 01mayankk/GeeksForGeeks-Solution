class Solution {
  public:
    bool areIsomorphic(string &s1, string &s2) {
        
        // If lengths are different, they cannot be isomorphic
        if(s1.size() != s2.size())
            return false;
        
        // map1 will store mapping from s1 → s2
        // map2 will store reverse mapping from s2 → s1
        // We use two maps to ensure one-to-one (bijective) mapping
        unordered_map<char, char> map1;
        unordered_map<char, char> map2;
        
        // Traverse both strings simultaneously
        for(int i = 0; i < s1.size(); i++) {
            
            char c1 = s1[i];  // current character from s1
            char c2 = s2[i];  // corresponding character from s2
            
            // If c1 is already mapped, check if it maps correctly
            if(map1.count(c1)) {
                // If previously mapped value doesn't match current c2 → not isomorphic
                if(map1[c1] != c2)
                    return false;
            } 
            else {
                // Create new mapping c1 → c2
                map1[c1] = c2;
            }
            
            // Now check reverse mapping to ensure no two characters
            // from s1 map to same character in s2
            if(map2.count(c2)) {
                // If reverse mapping conflicts → not isomorphic
                if(map2[c2] != c1)
                    return false;
            } 
            else {
                // Create reverse mapping c2 → c1
                map2[c2] = c1;
            }
        }
        
        // If no conflicts found, strings are isomorphic
        return true;
    }
};