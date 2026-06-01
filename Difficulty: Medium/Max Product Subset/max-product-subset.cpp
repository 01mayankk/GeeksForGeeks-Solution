class Solution {
public:
    int findMaxProduct(vector<int>& arr) {
        const int MOD = 1e9 + 7;

        // Stores the final product modulo MOD
        int product = 1;

        // Indicates whether we have formed
        // at least one positive contribution to the answer
        bool hasPositiveProduct = false;

        // Indicates presence of zero
        bool hasZero = false;

        // Used to store at most two unpaired negative numbers
        int firstNegative = 0;
        int secondNegative = 0;

        for (int num : arr) {

            // Positive number directly contributes
            // to the maximum product
            if (num > 0) {
                hasPositiveProduct = true;
                product = (1LL * product * num) % MOD;
            }

            // Handle negative numbers
            else if (num < 0) {

                // If we already have one negative stored
                if (firstNegative) {

                    // If we have two negatives waiting
                    if (secondNegative) {

                        hasPositiveProduct = true;

                        int current = num;

                        // Keep the two negatives with
                        // larger absolute values together
                        if (current > firstNegative)
                            swap(current, firstNegative);

                        if (firstNegative < secondNegative)
                            swap(firstNegative, secondNegative);

                        // Multiply a pair of negatives
                        // to contribute positively
                        product = (1LL * product *
                                  ((1LL * secondNegative * current) % MOD)) % MOD;

                        // Reset second slot
                        secondNegative = 0;
                    }
                    else {
                        secondNegative = num;
                    }
                }
                else {
                    firstNegative = num;
                }
            }

            // Track presence of zero
            else {
                hasZero = true;
            }
        }

        // If two negatives remain unpaired,
        // multiply them into the answer
        if (firstNegative < 0 && secondNegative < 0) {
            hasPositiveProduct = true;

            product = (1LL * product *
                      ((1LL * firstNegative * secondNegative) % MOD)) % MOD;
        }

        // If a positive product was formed,
        // return it
        if (hasPositiveProduct) {
            return product;
        }

        // Otherwise:
        // If zero exists, choosing zero gives
        // maximum product
        if (hasZero) {
            return 0;
        }

        // Only one negative element exists
        return arr[0];
    }
};