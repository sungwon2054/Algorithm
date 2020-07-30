#include <iostream>
#include <string>
#define endl '\n'

using namespace std;

string s;
string bomb;
char ans[1000001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s;
	cin >> bomb;
	
	int idx = 0;
	for (int i = 0; i < s.length(); i++) {
		ans[idx] = s[i];
		idx++;
		if (ans[idx - 1] == bomb[bomb.length() - 1]) {
			if (idx - (bomb.length() - 1) < 0) continue;

			bool flag = false;
			for (int j = 0; j < bomb.length(); j++) {
				if (ans[idx - j - 1] != bomb[(bomb.length() - 1) - j]) {
					flag = true;
				}
			}
			if (!flag) {
				idx -= bomb.length();
			}
		}
	}

	if (idx == 0) {
		cout << "FRULA" << endl;
	}
	else {
		for (int i = 0; i < idx; i++) {
			cout << ans[i];
		}
		cout << endl;
	}
}