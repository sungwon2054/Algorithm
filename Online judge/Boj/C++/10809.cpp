#include <iostream>
#include <string>
#include <cstring>
#define endl '\n'

using namespace std;

int alph[26];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;
	memset(alph, -1, sizeof(alph));
	for (int i = 0; i < s.size(); i++) {
		if (alph[s[i] - 'a'] == -1) {
			alph[s[i] - 'a'] = i;
		}
	}
	for (auto x : alph) {
		cout << x << ' ';
	}
}