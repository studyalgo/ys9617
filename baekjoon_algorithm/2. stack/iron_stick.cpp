#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	string str;
	cin >> str;
    
	size_t sum = 0, n = str.size();
	vector<int> vec;
	for (size_t i = 0; i < n; ++i) {
		if (i < n-1 && str[i] == '(' && str[i + 1] == ')') {
			for (auto &v : vec) v++;
			i++;
		}
		else if (str[i] == '(') {
			vec.emplace_back(1);
		}
		else if (str[i] == ')') {
			sum += vec.back();
			vec.pop_back();
        }
	}

	cout << sum << "\n";

	return 0;
}