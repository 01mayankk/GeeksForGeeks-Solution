class Solution {
public:
    vector<bool> processQueries(vector<int> &arr, vector<vector<int>> &queries) {

        int n = arr.size();

        // ------------------------------------------------------------
        // incEnd[i] = Farthest index we can reach starting from index i
        //             while the sequence remains non-decreasing.
        //
        // Example:
        // arr = [2, 3, 4, 4, 1]
        //
        // incEnd = [3, 3, 3, 3, 4]
        //
        // Starting from index 0:
        // 2 <= 3 <= 4 <= 4
        // We can go till index 3.
        // ------------------------------------------------------------
        vector<int> incEnd(n);
        incEnd[n - 1] = n - 1;

        // Traverse from right to left so that incEnd[i + 1]
        // has already been computed.
        for (int i = n - 2; i >= 0; i--) {

            // If current element is <= next element,
            // we can extend the non-decreasing sequence.
            if (arr[i] <= arr[i + 1])
                incEnd[i] = incEnd[i + 1];

            // Otherwise, the sequence breaks here.
            else
                incEnd[i] = i;
        }


        // ------------------------------------------------------------
        // decEnd[i] = Farthest index we can reach starting from index i
        //             while the sequence remains non-increasing.
        //
        // Example:
        // arr = [5, 5, 4, 3, 6]
        //
        // decEnd = [3, 3, 3, 3, 4]
        //
        // Starting from index 0:
        // 5 >= 5 >= 4 >= 3
        // We can go till index 3.
        // ------------------------------------------------------------
        vector<int> decEnd(n);
        decEnd[n - 1] = n - 1;

        // Again process from right to left.
        for (int i = n - 2; i >= 0; i--) {

            // Current element can continue the
            // non-increasing sequence.
            if (arr[i] >= arr[i + 1])
                decEnd[i] = decEnd[i + 1];

            // Otherwise the decreasing sequence ends here.
            else
                decEnd[i] = i;
        }


        vector<bool> ans;

        // ------------------------------------------------------------
        // Process every query independently.
        // ------------------------------------------------------------
        for (auto &q : queries) {

            int l = q[0];
            int r = q[1];

            // --------------------------------------------------------
            // Step 1:
            // Starting from the left boundary, move as far as possible
            // while the sequence is non-decreasing.
            //
            // This gives the highest possible "peak".
            // --------------------------------------------------------
            int peak = incEnd[l];

            // --------------------------------------------------------
            // Step 2:
            // From this peak, check whether we can continue
            // with a non-increasing sequence till index r.
            //
            // If yes:
            //
            //      increasing
            //  l -------------> peak
            //                     |
            //                     |
            //                     v
            //               decreasing
            //              peak -------> r
            //
            // Then the entire subarray forms a mountain.
            // --------------------------------------------------------
            ans.push_back(decEnd[peak] >= r);
        }

        return ans;
    }
};