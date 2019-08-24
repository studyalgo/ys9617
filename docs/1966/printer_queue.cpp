#include <iostream>
#include <list>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T, N, M, elm;
    cin >> T;

    for (int t = 1; t <= T; ++t) {
        cin >> N >> M;
        list<pair<int, int>> lst;

        for (int i = 0; i < N; ++i) {
            cin >> elm;
            lst.push_back(make_pair(elm, i));
        }

        int result = 1;
        while (!lst.empty()) {
            bool is_pop = false;
            for (auto l = ++lst.begin(); l != lst.end(); ++l) {
                if (l->first > lst.front().first) {
                    pair<int, int> tmp = lst.front();
                    lst.pop_front();
                    lst.push_back(tmp);
                    is_pop = true;
                    break;
                }
            }

            if (is_pop == false) {
                if (lst.front().second == M) {
                    cout << result << "\n";
                    break;
                }

                lst.pop_front();
                result++;
            }
        }
    }

    return 0;
}