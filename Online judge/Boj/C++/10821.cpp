#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	getline(cin, s);
	int ans = 1;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ',')
			ans++;
	}
	cout << ans << '\n';
}