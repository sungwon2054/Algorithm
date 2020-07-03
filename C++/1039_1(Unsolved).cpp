/*
N�� ������ 0 < N < 1,000,000�̹Ƿ� 
�ִ� 999,999�̴�. ���� dfs�� Ǯ ��� 5! (���� �պ��� ���� �ڱ��� �ٲٴ� ���)�̴�.
K�� ������ �ִ� 10 �̹Ƿ�
O(N) = 5! ^ 10 �� �ǹǷ� �Ұ����ϴ�.

�˻���� ��Ʈ��ŷ ������� �̹� ���� ���� �� �̻� ã�� �ʰ� Ǭ ��αװ� �־��µ�
�ؿ� �ִ� �ڵ�� �� �ȵǴ��� �𸣰ڴ�..

2% �ð��ʰ�
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