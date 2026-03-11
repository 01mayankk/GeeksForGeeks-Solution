class Solution {
public:
    int sumSubMins(vector<int> &arr) {
        
        int n = arr.size();
        
        vector<int> ple(n); // previous less element index
        vector<int> nle(n); // next less element index
        
        stack<int> st;
        
        // -------- Find Previous Less Element (PLE) --------
        for(int i = 0; i < n; i++)
        {
            // Pop elements greater than current
            while(!st.empty() && arr[st.top()] > arr[i])
                st.pop();
            
            if(st.empty())
                ple[i] = -1;        // no smaller element on left
            else
                ple[i] = st.top();  // index of previous smaller
            
            st.push(i);
        }
        
        // clear stack for next computation
        while(!st.empty()) st.pop();
        
        
        // -------- Find Next Less Element (NLE) --------
        for(int i = n-1; i >= 0; i--)
        {
            // Pop elements greater or equal
            while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            
            if(st.empty())
                nle[i] = n;         // no smaller element on right
            else
                nle[i] = st.top();  // index of next smaller
            
            st.push(i);
        }
        
        
        // -------- Calculate total sum --------
        long long result = 0;
        
        for(int i = 0; i < n; i++)
        {
            long long left = i - ple[i];     // choices on left
            long long right = nle[i] - i;    // choices on right
            
            // contribution of arr[i]
            result += arr[i] * left * right;
        }
        
        return (int)result;
    }
};