#include <vector>
#include <stack>

using namespace std;

// O(N^2)
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

// O(N)
vector<int> solution2(vector<int> prices) {
    vector<int> answer(prices.size());
    
    stack<int> stk;
    stk.push(prices.size()-1);
    
    for (int i = prices.size()-2; i >= 0; --i) {
        while (!stk.empty() && prices[stk.top()] >= prices[i]) {
            stk.pop();
        }
        
        answer[i] = stk.empty() ? prices.size()-i-1 : stk.top()-i;
        
        stk.push(i);
    }
    
    return answer;
}