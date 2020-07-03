/*
1번 바꾸는것부터 K번 바꾸는것까지 확인을하며 queue에 (숫자, depth번 바꾼 횟수) 계속 넣어준다 
그럼 바꾸는 모든 경위의 수가 다 queue에 저장되고 중복을 제거하기 위해
set을 사용한다. set으로 (숫자, depth)을 확인하여 중복되지 않으면 계속 queue에 추가한다
depth번 바꾼 횟수 == K가 된 순간
queue 안에 있는 모든 숫자 중 최댓값을 출력한다
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
	set<pair<string,int> > check_num; //중복체크
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