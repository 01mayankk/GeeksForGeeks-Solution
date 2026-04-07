class Solution {
public:
    vector<int> stableMarriage(vector<vector<int>> &men, vector<vector<int>> &women) {
        
        int n = men.size();

        // result[i] = index of woman matched with man i
        vector<int> result(n, -1);

        // womanPartner[j] = index of man currently matched with woman j
        // -1 means the woman is free
        vector<int> womanPartner(n, -1);

        // nextProposal[i] = index of next woman in preference list
        // to whom man i will propose
        vector<int> nextProposal(n, 0);

        // rank[w][m] = priority of man 'm' in woman 'w''s preference list
        // Smaller value means higher preference
        vector<vector<int>> rank(n, vector<int>(n));

        // -------------------------------
        // Step 1: Precompute ranking table
        // -------------------------------
        // This allows O(1) comparison:
        // "Does woman prefer man A over man B?"
        for (int w = 0; w < n; w++) {
            for (int i = 0; i < n; i++) {
                int man = women[w][i];
                rank[w][man] = i;
            }
        }

        // -------------------------------
        // Step 2: Initialize all men as free
        // -------------------------------
        queue<int> freeMen;
        for (int i = 0; i < n; i++) {
            freeMen.push(i);
        }

        // -------------------------------
        // Step 3: Gale-Shapley Algorithm
        // -------------------------------
        while (!freeMen.empty()) {

            // Pick a free man
            int man = freeMen.front();
            freeMen.pop();

            // Get the next woman he has not yet proposed to
            int woman = men[man][nextProposal[man]];
            nextProposal[man]++;  // Move to next preference for future

            // Case 1: Woman is free → accept proposal
            if (womanPartner[woman] == -1) {
                womanPartner[woman] = man;
                result[man] = woman;
            }
            else {
                // Woman is already engaged
                int currentMan = womanPartner[woman];

                // Check if she prefers new man over current partner
                if (rank[woman][man] < rank[woman][currentMan]) {
                    // She prefers the new man

                    // Break engagement with current partner
                    womanPartner[woman] = man;
                    result[man] = woman;

                    // Previous partner becomes free again
                    freeMen.push(currentMan);
                    result[currentMan] = -1;
                }
                else {
                    // She rejects the new proposal
                    // Man remains free and will try next woman
                    freeMen.push(man);
                }
            }
        }

        // -------------------------------
        // Step 4: Return final matching
        // -------------------------------
        return result;
    }
};