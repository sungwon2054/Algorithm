/*
N의 범위는 0 < N < 1,000,000이므로 
최대 999,999이다. 따라서 dfs로 풀 경우 5! (제일 앞부터 제일 뒤까지 바꾸는 경우)이다.
K의 범위가 최대 10 이므로
O(N) = 5! ^ 10 이 되므로 불가능하다.

검색결과 백트레킹 방법으로 이미 갔던 곳은 더 이상 찾지 않고 푼 블로그가 있었는데
밑에 있는 코드는 왜 안되는지 모르겠다..

2% 시간초과
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string N; 
int K;
int ans;
bool d[1000001][11];

void dfs(string num, int depth) {
	if (depth == K) {
		ans = max(stoi(num), ans);
		return;
	}
	if (d[stoi(num)][depth]) return;
	for (int i = 0; i < num.size() - 1; i++) {
		for (int j = i + 1; j < num.size(); j++) {
			swap(num[i], num[j]);
			if (num[0] == '0') {
				swap(num[i], num[j]);
				continue;
			}
			d[stoi(num)][depth] = true;
			dfs(num, depth + 1);

			swap(num[i], num[j]);
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;
	dfs(N, 0);
	if (ans == 0)
		cout << -1 << '\n';
	else
		cout << ans << '\n';
}