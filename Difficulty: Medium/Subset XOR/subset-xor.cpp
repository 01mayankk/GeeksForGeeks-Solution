class Solution {
public:
    vector<int> subsetXOR(int n) {
        vector<int> result;

        // ---------------------------------------------------------
        // Step 1 → Compute XOR of all numbers from 1 to n
        // xorAll = 1 ^ 2 ^ 3 ... ^ n
        // We want final subset XOR = n
        // ---------------------------------------------------------
        int xorAll = 0;
        for(int i = 1; i <= n; i++)
            xorAll ^= i;


        // ---------------------------------------------------------
        // Case 1: If XOR of full range (1..n) is already = n
        // Then the largest possible subset is the entire range.
        // Also lexicographically smallest.
        //
        // Example:
        // n = 4 → 1^2^3^4 = 4 → answer = [1,2,3,4]
        // ---------------------------------------------------------
        if(xorAll == n) {
            for(int i = 1; i <= n; i++)
                result.push_back(i);
            return result;
        }


        // ---------------------------------------------------------
        // Case 2: XOR != n → We need to FIX IT.
        // We must remove (xorAll ^ n) because:
        //
        // Let need = xorAll ^ n
        // Removing 'need' from 1..n flips final XOR to exactly n.
        //
        // Target:
        //      (xorAll ^ need) == n
        // →    need = xorAll ^ n
        //
        // If need is between [1..n], we remove it.
        // The subset size becomes n-1 (maximum possible other than full).
        // Lexicographically smallest as removal is a single value.
        // ---------------------------------------------------------
        int need = xorAll ^ n;

        if(need >= 1 && need <= n) {
            for(int i = 1; i <= n; i++)
                if(i != need)               // remove exactly one number
                    result.push_back(i);
            return result;
        }


        // ---------------------------------------------------------
        // Case 3: If need is NOT within [1..n]
        // Removing a number won't work.
        // Instead, we include ALL numbers + 'need' as an extra element.
        //
        // Why valid?
        // XOR(1..n)^need == n  → Adding it corrects XOR perfectly
        //
        // Subset size = n+1 → even larger (best possible)
        // And lexicographically smallest since new number is last.
        // ---------------------------------------------------------
        for(int i = 1; i <= n; i++)
            result.push_back(i);

        result.push_back(need);             // append extra number to correct XOR

        return result;
    }
};
