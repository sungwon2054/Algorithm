#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int N, M;
map<string, int> listen;
vector<string> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		listen[s] += 1;
	}
	for (int i = 0; i < M; i++) {
		string s;
		cin >> s;
		listen[s] += 2;
	}
	for (auto x : listen) {
		if (x.second == 3)
			v.push_back(x.first);
	}
	cout << v.size() << '\n';
	for (auto x : v)
		cout << x << '\n';
}