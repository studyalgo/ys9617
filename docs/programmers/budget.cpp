#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int solution(vector<int> budgets, int M) {
    long long answer = 0;
    
    if (accumulate(begin(budgets), end(budgets), 0LL) <= M) {
        answer = *max_element(begin(budgets), end(budgets));
    }
    else {
        sort(begin(budgets), end(budgets));
        
        int l_idx = 0, r_idx = budgets.size()-1, m_idx = 0;
        
        while (l_idx <= r_idx) {
            m_idx = (l_idx + r_idx) / 2;
            
            long long bm_sum = accumulate(begin(budgets), begin(budgets) + m_idx + 1, 0LL);
            long long me_sum = (budgets.size()-1 - m_idx) * budgets[m_idx];
            
            if (bm_sum + me_sum > M) {
                r_idx = m_idx-1;
            }
            else {
                l_idx = m_idx+1;
            }
        }
        
        if (m_idx > r_idx) m_idx--;
        
        long long tmp = accumulate(begin(budgets), begin(budgets) + m_idx + 1, 0LL);
        
        answer = (M - tmp) / (budgets.size() - m_idx - 1);
    }
    
    return answer;
}