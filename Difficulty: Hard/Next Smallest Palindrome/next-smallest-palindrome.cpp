class Solution {
public:
    vector<int> nextPalindrome(vector<int>& num) {
        int n = num.size();
        
        // Step 1: Check if all digits are 9
        bool all9 = true;
        for (int i = 0; i < n; i++) {
            if (num[i] != 9) {   // if any digit is not 9
                all9 = false;
                break;
            }
        }
        
        // If all digits are 9 → next palindrome is 100...001
        // Example: 999 → 1001
        if (all9) {
            vector<int> res(n + 1, 0); // size increases by 1
            res[0] = 1;               // first digit = 1
            res[n] = 1;               // last digit = 1
            return res;
        }
        
        // Copy original number to result
        vector<int> res = num;
        
        // Step 2: Mirror left half to right half
        int i = 0, j = n - 1;
        while (i < j) {
            res[j] = res[i];  // copy left digit to right
            i++;
            j--;
        }
        
        // Step 3: If mirrored number is already greater → return it
        if (res > num) {
            return res;
        }
        
        // Step 4: Otherwise, increment the middle and handle carry
        int carry = 1;        // we need to add 1
        int mid = n / 2;
        
        // Case 1: Odd length → increment middle element
        if (n % 2 == 1) {
            res[mid] += 1;               // add 1 to middle
            carry = res[mid] / 10;       // check if carry generated
            res[mid] %= 10;              // keep single digit
            
            i = mid - 1;                 // move left
            j = mid + 1;                 // move right
        } 
        // Case 2: Even length → start from middle two elements
        else {
            i = mid - 1;
            j = mid;
        }
        
        // Step 5: Propagate carry towards left and mirror to right
        while (i >= 0) {
            res[i] += carry;             // add carry
            carry = res[i] / 10;         // update carry
            res[i] %= 10;                // keep single digit
            
            res[j] = res[i];             // mirror left to right
            
            i--;
            j++;
        }
        
        return res;  // final palindrome
    }
};