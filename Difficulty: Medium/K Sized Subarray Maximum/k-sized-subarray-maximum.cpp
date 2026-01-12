class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {

        vector<int> result;       // Stores answer
        deque<int> dq;            // Will store indices of elements

        for (int i = 0; i < arr.size(); i++) {

            // 1️⃣ Remove elements which are out of this window
            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // 2️⃣ Remove elements smaller than current
            // They will never be needed
            while (!dq.empty() && arr[dq.back()] <= arr[i]) {
                dq.pop_back();
            }

            // 3️⃣ Add current index
            dq.push_back(i);

            // 4️⃣ Store max once first window is completed
            if (i >= k - 1) {
                result.push_back(arr[dq.front()]);
            }
        }

        return result;
    }
};
