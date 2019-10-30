#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    if (find(std::begin(words), end(words), target) == end(words)) return 0;
    
    int n = words.size();
    vector<vector<int>> link(n, vector<int>(n));
    
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            int cnt = 0;
            for (int k = 0; k < target.size(); ++k) {
                if (words[i][k] != words[j][k]) cnt++;
            }
            
            if (cnt == 1) {
                link[i][j] = link[j][i] = 1;
            }
        }
    }
           
    int start_idx = -1;
    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        for (int j = 0; j < begin.size(); ++j) {
            if (words[i][j] != begin[j]) cnt++;
        }
        
        if (cnt == 1) {
            start_idx = i;
        }
    }
    
    if (start_idx == -1) return 0;
    
    queue<pair<int, int>> que;
    vector<bool> visited(n);
    que.push(make_pair(start_idx, 1));
    
    while (!que.empty()) {
        int idx = que.front().first;
        int depth = que.front().second;
        
        que.pop();
        visited[idx] = true;
            
        if (words[idx] == target) {
            answer = depth;
            break;
        }
        
        for (int i = 0; i < n; ++i) {
            if (link[idx][i] == 1 && visited[i] == false) {
                que.push(make_pair(i, depth+1));
            }
        }
    }
    
    return answer;
}