vector<int> Smallestonleft(int arr[], int n) {
    set<int> s; // stores all previous elements in sorted order
    vector<int> result;

    for (int i = 0; i < n; i++) {
        auto it = s.lower_bound(arr[i]); // first element >= arr[i]

        if (it == s.begin()) {
            // no smaller element exists
            result.push_back(-1);
        } else {
            // greatest smaller element = previous one
            --it;
            result.push_back(*it);
        }

        // insert current element
        s.insert(arr[i]);
    }

    return result;
}

// vector<int> Smallestonleft(int arr[], int n) {
//     stack<int> s;  // will store potential smaller elements
//     vector<int> ans;

//     for (int i = 0; i < n; i++) {
//         // Pop all elements >= arr[i] (they can’t be smaller)
//         while (!s.empty() && s.top() >= arr[i])
//             s.pop();

//         // If stack is empty → no smaller element on left
//         if (s.empty())
//             ans.push_back(-1);
//         else
//             ans.push_back(s.top()); // top is nearest smaller

//         // Push current element
//         s.push(arr[i]);
//     }
//     return ans;
// }