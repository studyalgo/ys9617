#include <vector>
#include <stack>

using namespace std;

bool isLinked(vector<vector<int>> &link, int s, int d) {
    stack<int> stk;
    vector<bool> visited(link.size()), inStack(link.size());
    
    bool isFind1 = false, isFind2 = false;
    
    stk.push(s);
    inStack[s-1] = true;
    
    while (!stk.empty() && !isFind1) {
        int itm = stk.top();
        stk.pop();
        visited[itm-1] = true;
        inStack[itm-1] = false;
        
        for (int i = 1; i <= link.size(); ++i) {
            if (link[itm-1][i-1] == 1 && !visited[i-1] && !inStack[i-1]) {
                if (i == d) {
                    isFind1 = true;
                    break;
                }
                
                stk.push(i);
                inStack[i-1] = true;
            }
        }
    }
    
    if (isFind1) return true;
    
    while(!stk.empty()) stk.pop();
    for (size_t i = 0; i < link.size(); ++i) {
        visited[i] = inStack[i] = false;
    }
    
    stk.push(s);
    inStack[s-1] = true;
    
    while (!stk.empty() && !isFind2) {
        int itm = stk.top();
        stk.pop();
        visited[itm-1] = true;
        inStack[itm-1] = false;
        
        for (int i = 1; i <= link.size(); ++i) {
            if (link[itm-1][i-1] == 0 && link[i-1][itm-1] == 1 
                && !visited[i-1] && !inStack[i-1]) 
            {
                if (i == d) {
                    isFind2 = true;
                    break;
                }
                
                stk.push(i);
                inStack[i-1] = true;
            }
        }
    }
    
    return isFind2;
}

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    vector<vector<int>> link(n, vector<int>(n));
    
    for (auto r : results) {
        link[r[0]-1][r[1]-1] = 1;
    }
    
    for (int i = 1; i <= n; ++i) {
        bool isConnected = true;
        
        for (int j = 1; j <= n; ++j) {
            if (i != j && !isLinked(link, i, j)) {
                isConnected = false;
                break;
            }
        }
        
        if (isConnected) answer++;
    }
    
    return answer;
}