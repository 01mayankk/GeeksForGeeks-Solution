#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    void nearlySorted(vector<int>& arr, int k) {
        // Min-heap to store elements in sorted (ascending) order
        priority_queue<int, vector<int>, greater<int>> minHeap;

        int index = 0; // This keeps track of the current position to place the sorted element

        // Step 1: Insert the first (k + 1) elements into the min-heap
        // Because the smallest element must be within the first k+1 elements
        for (int i = 0; i <= k && i < arr.size(); i++) {
            minHeap.push(arr[i]);
        }

        // Step 2: For each remaining element in the array
        // - Pop the smallest element from the heap and place it in the sorted position
        // - Push the next element from the array into the heap
        for (int i = k + 1; i < arr.size(); i++) {
            arr[index++] = minHeap.top(); // Place the smallest element in its correct spot
            minHeap.pop();                 // Remove it from the heap
            minHeap.push(arr[i]);          // Add the next element into the heap
        }

        // Step 3: After traversing the array, empty the remaining elements in the heap
        // Each pop gives the next smallest element
        while (!minHeap.empty()) {
            arr[index++] = minHeap.top();
            minHeap.pop();
        }
    }
};
