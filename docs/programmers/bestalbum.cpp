#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    map<string, int> ht;
    
    for (size_t i = 0; i < genres.size(); ++i) {
        auto tmp = ht.find(genres[i]);
        
        if (tmp == end(ht)) {
            ht[genres[i]] = plays[i];
        }
        else {
            ht[genres[i]] += plays[i];
        }
    }
    
    vector<pair<string, int>> genre_plays(begin(ht), end(ht));
    sort(begin(genre_plays), end(genre_plays), [](pair<string,int> a, pair<string,int> b){
        return a.second > b.second;
    });
    
    for (auto g : genre_plays) {
        string genre = g.first;
        vector<pair<int, int>> vec;
        
        for (size_t i = 0; i < genres.size(); ++i) {
            if (genres[i] == genre) {
                vec.push_back(make_pair(plays[i], i));
            }
        }
        
        sort(begin(vec), end(vec), [](pair<int, int> a, pair<int, int> b){
            return a.first > b.first;
        });
        
        for (size_t i = 0; i < 2 && i < vec.size(); ++i) {
            answer.push_back(vec[i].second);
        }
    }
    
    return answer;
}