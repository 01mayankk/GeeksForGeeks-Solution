class Solution {
  public:
    int minCost(string &s, string &t, vector<vector<char>> &transform,
                vector<int> &cost) {
        // n: length of the input strings (they are guaranteed equal length)
        int n = s.size();

        // INF: sentinel large value used to represent "no path / unreachable"
        // Use a value comfortably larger than any possible real cost sum.
        const int INF = 1e9;

        // --------------------------------------------------------------------
        // Step 1: Build the adjacency (cost) matrix for the directed graph of
        //          transformations between the 26 lowercase letters.
        //
        // dist[i][j] will hold the minimum known cost to transform char (i+'a')
        // into char (j+'a'). Initialize to INF to mean "no direct route yet".
        // --------------------------------------------------------------------
        vector<vector<int>> dist(26, vector<int>(26, INF));

        // Cost to transform a letter to itself is zero (zero-length path).
        for (int i = 0; i < 26; i++)
            dist[i][i] = 0;

        // Fill direct transformation edges provided by 'transform' and 'cost'.
        // transform[k] is a vector<char> of size 2: {fromChar, toChar}.
        // We subtract 'a' to convert characters into indices 0..25.
        for (int i = 0; i < (int)transform.size(); i++) {
            int x = transform[i][0] - 'a'; // source letter index
            int y = transform[i][1] - 'a'; // destination letter index

            // There may be multiple edges between same pair with different costs,
            // so keep the minimum direct cost.
            dist[x][y] = min(dist[x][y], cost[i]);
        }

        // --------------------------------------------------------------------
        // Step 2: Floyd–Warshall algorithm to compute all-pairs shortest paths.
        //
        // After this, dist[i][j] will be the minimum cost to transform i->j
        // using any number (including zero) of intermediate transformations.
        // Complexity: O(26^3) which is effectively constant and tiny.
        // --------------------------------------------------------------------
        for (int k = 0; k < 26; k++) {
            // For each possible intermediate node 'k'
            for (int i = 0; i < 26; i++) {
                // Skip useless i->k if it's unreachable to speed up slightly.
                if (dist[i][k] == INF) continue;

                for (int j = 0; j < 26; j++) {
                    // If k->j is reachable, we can consider path i->k->j
                    if (dist[k][j] == INF) continue;

                    // Relax the path i->j via k
                    int cand = dist[i][k] + dist[k][j];
                    if (cand < dist[i][j]) dist[i][j] = cand;
                }
            }
        }

        // --------------------------------------------------------------------
        // Step 3: For each index position, determine the cheapest way to make
        //         s[i] and t[i] equal by possibly transforming each to some
        //         character c ('a'..'z'). We choose the c that minimizes:
        //             dist[s[i]][c] + dist[t[i]][c]
        //
        // If for any position no such c exists (i.e., one or both cannot reach
        // any common c), return -1.
        // --------------------------------------------------------------------
        long long answer = 0; // accumulate total cost in a 64-bit variable

        for (int i = 0; i < n; i++) {
            int a = s[i] - 'a'; // index of s[i]
            int b = t[i] - 'a'; // index of t[i]

            // best: track the cheapest combined cost for this position
            int best = INF;

            // Try every possible final character c (0..25)
            // converting both s[i] -> c and t[i] -> c.
            for (int c = 0; c < 26; c++) {
                // Both conversions must be possible (distance != INF)
                if (dist[a][c] < INF && dist[b][c] < INF) {
                    int combined = dist[a][c] + dist[b][c];
                    if (combined < best) best = combined;
                }
            }

            // If no common target c exists, it's impossible to make strings equal.
            if (best == INF) return -1;

            // Add the best cost for this position to the global answer.
            answer += best;

            // Small optimization / safety: if answer grows beyond INF return -1
            // (not strictly necessary given constraints, but guards overflow)
            if (answer >= (long long)INF) return -1;
        }

        // All positions processed successfully: return the accumulated cost.
        return (int)answer;
    }
};
