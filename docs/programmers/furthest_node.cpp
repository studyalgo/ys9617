#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    vector<vector<int>> link(n, vector<int>(n));
    
    for (size_t i = 0; i < edge.size(); ++i) {
        link[edge[i][0]-1][edge[i][1]-1] = link[edge[i][1]-1][edge[i][0]-1] = 1;
    }
    
    vector<bool> inqueue(n);
    vector<int> visited(n, -1);
    queue<int> q;
    
    q.push(0);
    visited[0] = 0;
    inqueue[0] = true;
    
    while (!q.empty()) {
        int node = q.front();
        inqueue[node] = false;
        
        q.pop();
        
        for (int i = 0; i < n; ++i) {
            if (visited[i] == -1 && !inqueue[i] && link[node][i]) {
                q.push(i);
                visited[i] = visited[node] + 1;
                inqueue[i] = true;
            }
        }
    }
    
    int max_depth = *max_element(begin(visited), end(visited));

    return count(begin(visited), end(visited), max_depth);
}