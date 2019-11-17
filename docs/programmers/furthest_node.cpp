#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    vector<vector<int>> link(n, vector<int>(n));
    
    for (size_t i = 0; i < edge.size(); ++i) {
        link[edge[i][0]-1][edge[i][1]-1] = link[edge[i][1]-1][edge[i][0]-1] = 1;
    }
    
    vector<bool> visited(n), inqueue(n);
    queue<pair<int, int>> q;
    
    q.push(make_pair(0, 0));
    inqueue[0] = true;
    
    int max_depth = 0;
    int depth_cnt = 0;
    
    while (!q.empty()) {
        int node = q.front().first;
        int depth = q.front().second;
        
        if (depth > max_depth) {
            max_depth = depth;
            depth_cnt = 1;
        }
        else {
            depth_cnt++;
        }
        
        visited[node] = true;
        inqueue[node] = false;
        
        q.pop();
        
        for (int i = 0; i < n; ++i) {
            if (!visited[i] && !inqueue[i] && link[node][i]) {
                q.push(make_pair(i, depth+1));
                inqueue[i] = true;
            }
        }
    }
    
    return depth_cnt;
}