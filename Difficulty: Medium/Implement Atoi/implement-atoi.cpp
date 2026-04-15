class Solution {
  public:
    int myAtoi(string &s) {
        
        int i = 0;                 // Pointer to traverse the string
        int n = s.length();        // Length of the string
        
        // Step 1: Ignore leading whitespaces
        while (i < n && s[i] == ' ') {
            i++;
        }
        
        // Step 2: Check sign (+ or -)
        int sign = 1;              // Default sign is positive
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') {
                sign = -1;         // Set sign to negative if '-' is found
            }
            i++;                   // Move to next character after sign
        }
        
        // Step 3: Read digits and form number
        long result = 0;           // Use long to safely detect overflow
        
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';   // Convert char to integer
            
            // Step 4: Check for overflow BEFORE updating result
            // If result > (INT_MAX - digit) / 10, adding next digit will overflow
            if (result > (INT_MAX - digit) / 10) {
                // Return max or min based on sign
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            
            // Update result by shifting left (×10) and adding digit
            result = result * 10 + digit;
            
            i++;   // Move to next character
        }
        
        // Step 5: Apply sign and return final result
        return sign * result;
    }
};