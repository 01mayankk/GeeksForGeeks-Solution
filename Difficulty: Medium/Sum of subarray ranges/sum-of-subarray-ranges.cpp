class Solution {
public:
    
    int subarrayRanges(vector<int>& arr) {
        int n = arr.size();

        // ------------------------------------------------------------
        // leftMin[i]  = number of elements to the LEFT of i
        //               where arr[i] is the MINIMUM
        // rightMin[i] = number of elements to the RIGHT of i
        //               where arr[i] is the MINIMUM
        //
        // leftMax[i]  = number of elements to the LEFT of i
        //               where arr[i] is the MAXIMUM
        // rightMax[i] = number of elements to the RIGHT of i
        //               where arr[i] is the MAXIMUM
        // ------------------------------------------------------------
        vector<int> leftMin(n), rightMin(n), leftMax(n), rightMax(n);

        // Stack will store indices (not values)
        stack<int> st;

        // ============================================================
        // PART 1: CALCULATE CONTRIBUTION AS SUBARRAY MINIMUM
        // ============================================================

        // ---- Previous Smaller Element (STRICTLY smaller) ----
        // We maintain a MONOTONIC INCREASING STACK
        for (int i = 0; i < n; i++) {

            // Remove elements greater than current element
            // because current element becomes the new minimum
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            // If stack is empty:
            // current element is the minimum for all elements to its left
            leftMin[i] = st.empty() ? (i + 1) : (i - st.top());

            // Push current index to stack
            st.push(i);
        }

        // Clear stack before reuse
        while (!st.empty()) st.pop();

        // ---- Next Smaller or Equal Element ----
        // We scan from RIGHT to LEFT
        for (int i = n - 1; i >= 0; i--) {

            // Remove elements greater than or equal to current element
            // (important to avoid double counting)
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            // If stack is empty:
            // current element is minimum for all elements to its right
            rightMin[i] = st.empty() ? (n - i) : (st.top() - i);

            st.push(i);
        }

        // ============================================================
        // PART 2: CALCULATE CONTRIBUTION AS SUBARRAY MAXIMUM
        // ============================================================

        while (!st.empty()) st.pop();

        // ---- Previous Greater Element (STRICTLY greater) ----
        // Maintain a MONOTONIC DECREASING STACK
        for (int i = 0; i < n; i++) {

            // Remove elements smaller than current
            while (!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }

            // Distance to previous greater element
            leftMax[i] = st.empty() ? (i + 1) : (i - st.top());

            st.push(i);
        }

        while (!st.empty()) st.pop();

        // ---- Next Greater or Equal Element ----
        for (int i = n - 1; i >= 0; i--) {

            // Remove elements smaller or equal
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }

            rightMax[i] = st.empty() ? (n - i) : (st.top() - i);

            st.push(i);
        }

        // ============================================================
        // PART 3: FINAL CALCULATION
        // ============================================================

        long long sumMin = 0; // Sum of all subarray minimums
        long long sumMax = 0; // Sum of all subarray maximums

        for (int i = 0; i < n; i++) {

            // Contribution of arr[i] as MINIMUM:
            // arr[i] * (#choices on left) * (#choices on right)
            sumMin += (long long) arr[i] * leftMin[i] * rightMin[i];

            // Contribution of arr[i] as MAXIMUM:
            sumMax += (long long) arr[i] * leftMax[i] * rightMax[i];
        }

        // ------------------------------------------------------------
        // Final Answer = Sum of Maximums - Sum of Minimums
        // Guaranteed to fit in 32-bit integer
        // ------------------------------------------------------------
        return (int)(sumMax - sumMin);
    }
};
