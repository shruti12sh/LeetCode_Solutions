class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
            vector<int> indegree(numCourses);
        vector<vector<int>> adj(numCourses);
        for (auto prerequisite : prerequisites) {
            adj[prerequisite[1]].push_back(prerequisite[0]);
            indegree[prerequisite[0]]++;
        }

        queue<int> q;
        // Push all the nodes with indegree zero in the queue.
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int>topo;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for (auto& neighbor : adj[node]) {
                // Delete the edge "node -> neighbor".
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        if(topo.size()==numCourses) return topo;
        return {};
    }
    
};