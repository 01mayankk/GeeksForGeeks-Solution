class Solution {
  public:
    int countSubarrays(vector<int> &arr) {
        
        int n = arr.size();
        
        // Stack will store indices of elements
        stack<int> st;
        
        long long ans = 0;
        
        // Traverse from right to left
        for(int i = n - 1; i >= 0; i--)
        {
            // Remove elements that are >= current element
            // because they cannot be next smaller
            while(!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            
            // If stack becomes empty
            // it means no smaller element to the right
            if(st.empty())
            {
                ans += (n - i);
            }
            else
            {
                // Next smaller element index
                ans += (st.top() - i);
            }
            
            // Push current index into stack
            st.push(i);
        }
        
        return ans;
    }
};