class Solution {
public:
    // Each state represents a group of substrings that share the same set of occurrences.
    struct State {
        int link, len;             // link = suffix link (like failure link), len = max length of substring in this state
        map<char,int> next;        // transitions for characters
        State() : link(-1), len(0) {}
    };
    
    vector<State> st;              // Suffix automaton list of states
    int last;                      // last = state representing whole current string

    // Constructor initializes SAM with a root state
    Solution() {
        st.reserve(6005);          // Reserve space for 2*N states (N ≤ 3000)
        st.push_back(State());     // Create initial root state
        last = 0;                  // Last points to root initially
    }
    
    // Extend SAM with character 'c'
    void extend(char c) {
        int cur = st.size();       // Index of new state
        st.push_back(State());
        st[cur].len = st[last].len + 1;   // Max length increases by 1
        
        int p = last;
        // Move backward along suffix links until a transition by 'c' is found
        while(p != -1 && !st[p].next.count(c)) {
            st[p].next[c] = cur;   // Create missing transition
            p = st[p].link;
        }
        
        // Case 1: reached root and no transition existed → link to root
        if(p == -1) st[cur].link = 0;
        else {
            int q = st[p].next[c];
            
            // Case 2: Length property already valid → link current to q
            if(st[p].len + 1 == st[q].len) st[cur].link = q;
            
            // Case 3: Need to split (clone) state q
            else {
                int clone = st.size();
                st.push_back(st[q]);       // Clone q into a new state
                st[clone].len = st[p].len + 1;  // adjust correct length
                
                // Redirect transitions that lead to q → now to clone
                while(p != -1 && st[p].next[c] == q) {
                    st[p].next[c] = clone;
                    p = st[p].link;
                }

                st[q].link = st[cur].link = clone; // Fix links
            }
        }
        last = cur; // update last
    }
    
    // Count distinct substrings using SAM
    int countSubs(string& s) {
        for(char c: s) extend(c);   // Build suffix automaton
        
        long long ans = 0;
        /*
            Key observation:
            Every state contributes (len[state] - len[link[state]]) new substrings.
        */
        for(int i=1;i<st.size();i++){
            ans += st[i].len - st[st[i].link].len;
        }
        return ans;
    }
};
