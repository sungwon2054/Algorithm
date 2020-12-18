#include <iostream>
#include <string>
#include <map>
#define endl '\n'
using namespace std;

int N;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		
		int cnt = 0;
		int score = 0;
		for (auto x : s) {
			if (x == 'O') {
				cnt++;
				score += cnt;
			}
			else{
				cnt = 0;
			}
		}
		cout << score << endl;
	}
}