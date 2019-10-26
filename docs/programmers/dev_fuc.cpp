#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer, days(speeds.size());
    
    for (size_t i = 0; i < days.size(); ++i) {
        days[i] = ceil((100.f - progresses[i]) / speeds[i]);
    }
    
    for (size_t i = 0, tmp = 1; i < days.size(); ++i) {
        if (i < days.size()-1 && days[i] >= days[i+1]) {
            days[i+1] = days[i];
            tmp++;
        }
        else {
            answer.push_back(tmp);
            tmp = 1;
        }
    }
    
    return answer;
}