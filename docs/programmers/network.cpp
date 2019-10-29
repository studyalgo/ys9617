#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    vector<int> cmp(computers.size());
            
    for (size_t i = 0; i < cmp.size(); ++i) {
        if (cmp[i] == 0) {
            stack<int> stk;
            stk.push(i);
                
            while (!stk.empty()) {
                int idx = stk.top();
                cmp[idx] = 1;
                stk.pop();
                    
                for (size_t j = 0; j < computers[idx].size(); ++j) {
                    if (cmp[j] == 0 && computers[idx][j] == 1) {
                        stk.push(j);
                    }
                }
            }
            
            answer++;
        }
    }
    
    return answer;
}