#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        // Step 1: Create adjacency list representation of the graph
        // Each index represents a course, and it stores a list of courses
        // that depend on it (i.e., the courses that come after it).
        vector<int> adj[n];
        
        // 'indegree[i]' will store the number of prerequisites for course 'i'
        vector<int> indegree(n, 0);

        // Step 2: Build the directed graph and fill indegree array
        // Each pair [course, prereq] means 'prereq → course'
        for (auto& pre : prerequisites) {
            int course = pre[0];   // The course we want to take
            int prereq = pre[1];   // The prerequisite course that must come first
            
            adj[prereq].push_back(course); // Add edge from prereq to course
            indegree[course]++;            // Increment indegree of the dependent course
        }

        // Step 3: Initialize a queue with all courses having indegree = 0
        // These courses have no prerequisites, so they can be taken first.
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // Step 4: Perform BFS-based Topological Sort (Kahn’s Algorithm)
        vector<int> order;  // To store the valid order of courses
        
        while (!q.empty()) {
            // Pick a course that has no remaining prerequisites
            int course = q.front();
            q.pop();
            
            // Add this course to the final order
            order.push_back(course);

            // Traverse all the courses that depend on this course
            for (int next : adj[course]) {
                // Since we have taken this course, reduce indegree of the dependent course
                indegree[next]--;
                
                // If indegree becomes 0, it means all prerequisites are done
                if (indegree[next] == 0) {
                    q.push(next);
                }
            }
        }

        // Step 5: If we were able to take all courses, return the order
        // Otherwise, there exists a cycle, meaning it's impossible to finish all
        if ((int)order.size() == n) {
            return order;  // Valid topological ordering found
        } else {
            return {};     // Cycle detected, no valid ordering possible
        }
    }
};
