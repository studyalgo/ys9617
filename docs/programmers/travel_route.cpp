#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(vector<vector<string>> &tickets, vector<bool> visited, vector<string> &path, bool &isFind) {
    if (path.size() <= tickets.size()+1 && isFind == false) {
        string from = path.back();
        
        if (path.size() == tickets.size()+1) isFind = true;
        
        for (size_t i = 0; i < tickets.size(); ++i) {
            if (visited[i] == false && tickets[i][0] == from) {
                visited[i] = true;
                path.push_back(tickets[i][1]);
                
                dfs(tickets, visited, path, isFind);
                
                if (isFind) break;
                
                visited[i] = false;
                path.pop_back();
            }
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer = { "ICN" };
    
    sort(begin(tickets), end(tickets));
    vector<bool> visited(tickets.size());
    bool isFind = false;
    
    dfs(tickets, visited, answer, isFind);
    
    return answer;
}