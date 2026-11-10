vector<int> findOrder(int numofcourse,vector<vector<int>>& prerequisites) {

    vector<vector<int>> adj(numofcourse);
    vector<int> indegree(numofcourse, 0);

    queue<int> q;
    vector<int> ans;

    // Build adjacency list and calculate indegree
    for(auto &p : prerequisites) {
        int course = p[0];
        int prerequisite = p[1];

        adj[prerequisite].push_back(course);
        indegree[course]++;
    }

    // Add all nodes with indegree 0
    for(int i = 0; i < numofcourse; i++) {
        if(indegree[i] == 0)
            q.push(i);
    }

    // BFS (Kahn's Algorithm)
    while(!q.empty()) {

        int top = q.front();
        q.pop();

        ans.push_back(top);

        for(int next : adj[top]) {

            indegree[next]--;

            if(indegree[next] == 0)
                q.push(next);
        }
    }

    // Cycle detection
    if(ans.size() != numofcourse)
        return {};

    return ans;
}
