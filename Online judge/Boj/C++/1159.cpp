#include <iostream>
#include <string>
#include <map>

using namespace std;

int N;
map<char, int> m;
string ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		char first = s[0];
		if (m.find(first) != m.end()) {
			m[first] += 1;
		}
		else {
			m.insert(make_pair(first, 1));
		}
	}
	for (auto x : m) {
		if (x.second >= 5)
			ans += x.first;
		//cout << x.first << x.second << endl;
	}

	if (ans!="") {
		cout << ans;
	}
	else {
		cout << "PREDAJA";
	}
}