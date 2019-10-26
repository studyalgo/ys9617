#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int elapsed_time;

    vector<pair<int, int>> bridge;

    for (elapsed_time = 0; !bridge.empty() || !truck_weights.empty(); ++elapsed_time) {
        if (!bridge.empty() && bridge.front().second >= bridge_length) {
            bridge.erase(begin(bridge));
        }
        
        int sum_bridge = 0;
        for (auto b : bridge) sum_bridge += b.first;

        if (!truck_weights.empty() && sum_bridge + truck_weights.front() <= weight) {
            bridge.push_back(make_pair(truck_weights.front(), 0));
            truck_weights.erase(begin(truck_weights));
        }

        for (auto& b : bridge) b.second++;
    }

    return elapsed_time;
}