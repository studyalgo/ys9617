#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    unordered_map<string, int> hash;
    
    for (size_t i = 0; i < clothes.size(); ++i) {
        hash[clothes[i][1]]++;
    }
    
    for (auto h : hash) {
        answer *= (h.second + 1);
    }
    
    return answer-1;
}