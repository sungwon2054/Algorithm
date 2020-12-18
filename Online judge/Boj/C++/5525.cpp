#include <iostream>
#include <string>
#include <map>
#define endl '\n'
using namespace std;

int N,M;
/*
1. s1을 입력받고 substr로 자르니 N * M 으로 시간초과
*/
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s1;
	int ans = 0;
	cin >> N >> M >> s1;
	for (int i = 0; i < M; i++) {
		if (s1[i] == 'I') {
			int count = 0;
			while (s1[i + 1] == 'O' && s1[i + 2] == 'I') {
				count++;
				if (count == N) {
					count--;
					ans++;
				}
				i = i + 2;
			}
		}
	}
	cout << ans << endl;
}