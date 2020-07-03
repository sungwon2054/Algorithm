/*
1�� �ٲٴ°ͺ��� K�� �ٲٴ°ͱ��� Ȯ�����ϸ� queue�� (����, depth�� �ٲ� Ƚ��) ��� �־��ش� 
�׷� �ٲٴ� ��� ������ ���� �� queue�� ����ǰ� �ߺ��� �����ϱ� ����
set�� ����Ѵ�. set���� (����, depth)�� Ȯ���Ͽ� �ߺ����� ������ ��� queue�� �߰��Ѵ�
depth�� �ٲ� Ƚ�� == K�� �� ����
queue �ȿ� �ִ� ��� ���� �� �ִ��� ����Ѵ�
*/

#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;

string N;
int K;

int main() {
	ios::sync_with_stdio(0);
	cin.tie();
	
	cin >> N >> K;
	set<pair<string,int> > check_num; //�ߺ�üũ
	queue<pair<string, int> > q;
	q.push({ N, 0 });
	while (!q.empty()) {
		string num = q.front().first;
		int cnt = q.front().second;
		if (cnt == K) break;
		q.pop();

		for (int i = 0; i < N.size() - 1; i++) {
			for (int j = i + 1; j < N.size(); j++) {
				swap(num[i], num[j]);
				if (num[0] == '0') {
					swap(num[i], num[j]);
					continue;
				}
				
				if (check_num.find({ num, cnt + 1 }) == check_num.end()) {
					q.push({ num, cnt + 1 });
					check_num.insert({ num, cnt + 1 });
				}
				swap(num[i], num[j]);
			}
		}
	}
	int ans = 0;
	while (!q.empty()) {
		ans = max(ans, stoi(q.front().first));
		q.pop();
	}
	if (ans == 0)
		cout << -1 << '\n';
	else
		cout << ans << '\n';
}