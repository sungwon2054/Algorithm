#include <iostream>
#include <string>
#define endl '\n'

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	string s1;
	/*
	모든 파일의 끝은 EOF가 붙어있다.
	terminal에서 입력시에는 직접 넣어줘야함 (ctrl + Z or ctrl + D) 
	*/
	while (cin >> s1) {
		if (cin.eof() == true) {
			break;
		}
		s += s1;
	}
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