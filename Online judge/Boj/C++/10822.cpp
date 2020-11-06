#include <iostream>
#include <string>
#define endl '\n'

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	getline(cin, s);
	string number;
	long long ans = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ',') {
			ans += stoll(number);
			number = "";
		}
		else{
			number += s[i];
		}
	}
	ans += stoi(number);
	cout << ans << endl;
}