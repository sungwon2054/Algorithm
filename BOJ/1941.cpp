/*
ó������ �Ϲ����� DFS�� Ǯ������
ex)
YYYYY
YYSYY
YSYSY
YYSYY
YYYYY
�� ���
Y**YY
YY*YY
Y***Y
YY*YY
YYYYY
�� case�� �� ã��
���� ��ü�� ��쿡�� ���Ƿ� 7���� �̾��� �� ĥ���ְ� �� ��츦 ã��.
*/


#include <iostream>
#include <queue>
#include <string>
#define endl '\n'
using namespace std;

char map[6][6];
bool chk[26];
int ans;
int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };

void Bfs() {
	queue<pair<int, int> > q;
	bool CheckingMap[5][5] = { 0 };
	int NewMap[5][5] = { 0 };

	bool flag = false;
	for (int i = 0; i < 25; i++) {
		if (chk[i]) {
			int y = i / 5;
			int x = i % 5;
			NewMap[y][x] = 1;
			if (!flag) {
				q.push({ y,x });
				CheckingMap[y][x] = true;
				flag = true;
			}
		}
	}
	int numbering = 1;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (0 > ny || ny >= 5 || 0 > nx || nx >= 5) continue;
			if (CheckingMap[ny][nx]) continue;
			if (NewMap[ny][nx] == 0) continue;
			q.push({ ny,nx });
			CheckingMap[ny][nx] = true;
			numbering++;
		}
	}
	if (numbering == 7) {
		ans++;
	}
}

bool CheckingSom() {
	int cnt = 0;
	for (int i = 0; i < 25; i++) {
		if (chk[i]) {
			int y = i / 5;
			int x = i % 5;
			if (map[y][x] == 'S')
				cnt++;
		}
	}
	if (cnt >= 4) return true;
	else return false;
}

void DFS(int idx, int cnt) {
	if (cnt == 7) {
		if (CheckingSom()) {//'��'�� �л� 4�� �̻����� üũ
			Bfs();
		}
		return;
	}

	for (int i = idx; i < 25; i++) {
		if (!chk[i]) {
			chk[i] = true;
			DFS(i, cnt + 1);
			chk[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 5; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			map[i][j] = s[j];
		}
	}

	DFS(0, 0);
	cout << ans << endl;
}