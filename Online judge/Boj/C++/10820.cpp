#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (1) {
		string s;
		getline(cin, s);
		if (s.length() == 0) break;
		int small = 0, capital = 0, number = 0, space = 0;
		for (int i = 0; i < s.length(); i++) {
			if (65 <= s[i] && s[i] <= 90) {
				capital++;
			}
			else if (97 <= s[i] && s[i] <= 122) {
				small++;
			}
			else if (48 <= s[i] && s[i] <= 57) {
				number++;
			}
			else if (s[i] == 32) {
				space++;
			}
		}
		cout << small << ' ' << capital << ' ' << number << ' ' << space << '\n';
	}
}