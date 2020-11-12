#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define endl '\n'

using namespace std;

int ans = 1e9;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string s1, s2;
	cin >> s1 >> s2;
	for (int i = 0; i < s2.size() - s1.size() + 1; i++) {
		int count = 0;
		for (int j = 0; j < s1.size(); j++) {
			if (s1[j] != s2[j+i]) {
				count++;
			}
		}
		ans = min(ans, count);
	}
	cout << ans << endl;
}