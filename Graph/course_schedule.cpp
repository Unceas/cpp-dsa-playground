#include <bits/stdc++.h>
using namespace std;

// Course Schedule
bool canFinish(int numCourses,
               vector<vector<int>>& prerequisites) {

    vector<vector<int>> graph(numCourses);
    vector<int> indegree(numCourses, 0);

    for(auto& p : prerequisites) {
        graph[p[1]].push_back(p[0]);
        indegree[p[0]]++;
    }

    queue<int> q;

    for(int i = 0; i < numCourses; i++) {
        if(indegree[i] == 0)
            q.push(i);
    }

    int completed = 0;

    while(!q.empty()) {

        int node = q.front();
        q.pop();

        completed++;

        for(int nei : graph[node]) {

            indegree[nei]--;

            if(indegree[nei] == 0)
                q.push(nei);
        }
    }

    return completed == numCourses;
}

int main() {

    int numCourses = 2;

    vector<vector<int>> prerequisites = {
        {1,0}
    };

    cout << (canFinish(numCourses, prerequisites)
             ? "Possible"
             : "Impossible");

    return 0;
}
