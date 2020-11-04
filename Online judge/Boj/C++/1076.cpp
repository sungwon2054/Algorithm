#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string, int> ohm;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	ohm["black"] = 0;
	ohm["brown"] = 1;
	ohm["red"] = 2;
	ohm["orange"] = 3;
	ohm["yellow"] = 4;
	ohm["green"] = 5;
	ohm["blue"] = 6;
	ohm["violet"] = 7;
	ohm["grey"] = 8;
	ohm["white"] = 9;

	long long ans = 0;
	for (int i = 0; i < 3; i++) {
		string s;
		cin >> s;
		if (i == 2) {
			if (ohm[s] != 0) {
				for (int i = 0; i < ohm[s]; i++) {
					ans *= 10;
				}
			}
		}
		else {
			ans *= 10;
			ans += ohm[s];
		}
	}
	cout << ans << '\n';
}