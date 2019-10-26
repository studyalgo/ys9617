#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    
    for (size_t i = 0; i < prices.size()-1; ++i) {
        int cnt = 1;
        
        for (size_t j = i+1; j < prices.size()-1; ++j) {
            if (prices[j] >= prices[i]) cnt++;
            else break;
        }
        
        answer[i] = cnt;
    }
    
    return answer;
}