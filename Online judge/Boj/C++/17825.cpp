#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

struct Data {
	int y, x, s;
};
Data mal[4];
stack<Data> pre_mal[4];
int map[4][42];
int input[10];
int ans = 0;
bool finishMal[4];

int move(int idx, int choice) {//몇번째판, 말선택
	int y = mal[choice].y;
	int x = mal[choice].x;
	int s = mal[choice].s;
	pre_mal[choice].push({ y,x,s });

	for (int i = 0; i < input[idx]; i++) {
		x = map[y][x];
		if (x == 41) {
			mal[choice].y = y;
			mal[choice].x = x;
			mal[choice].s = s;
			finishMal[choice] = true;
			return 2;
		}
	}
	for (int i = 0; i < 4; i++) {
		if (finishMal[i]) continue;
		if (i == choice) continue;
		if (y == mal[i].y && x == mal[i].x) {
			pre_mal[choice].pop();
			return 1;
		}
		if (x == 25 || x == 31 || x == 35 || x == 40 || x== 10 || x == 20 || x == 30) {
			if (x == mal[i].x) {
				pre_mal[choice].pop();
				return 1;
			}
		}
	}
	s += x;
	if (x == 31) s--;

	if (y == 0) {
		if (x == 10) {
			y = 1;
		}
		else if (x == 20) {
			y = 2;
		}
		else if (x == 30) {
			y = 3;
		}
	}
	mal[choice].y = y;
	mal[choice].x = x;
	mal[choice].s = s;
	return 0;
}

void goDice(int idx) {
	if (idx == 10) {
		int score = 0;
		for (int i = 0; i < 4; i++) {
			score += mal[i].s;
		}
		ans = max(ans, score);
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (finishMal[i]) continue;
		int flag = move(idx, i);
		if (flag == 1)
			continue;
		goDice(idx + 1);
		if (flag == 2) {
			finishMal[i] = false;
		}
		mal[i].y = pre_mal[i].top().y;
		mal[i].x = pre_mal[i].top().x;
		mal[i].s = pre_mal[i].top().s;
		pre_mal[i].pop();
	}
}

void drawMap() {
	for (int i = 0; i < 40; i = i + 2) {
		map[0][i] = i + 2;
	}
	map[0][40] = 41;

	map[1][10] = 13;
	map[1][13] = 16;
	map[1][16] = 19;
	map[1][19] = 25;
	map[1][25] = 31;
	map[1][31] = 35;
	map[1][35] = 40;
	map[1][40] = 41;

	map[2][20] = 22;
	map[2][22] = 24;
	map[2][24] = 25;
	map[2][25] = 31;
	map[2][31] = 35;
	map[2][35] = 40;
	map[2][40] = 41;

	map[3][30] = 28;
	map[3][28] = 27;
	map[3][27] = 26;
	map[3][26] = 25;
	map[3][25] = 31;
	map[3][31] = 35;
	map[3][35] = 40;
	map[3][40] = 41;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	drawMap();
	for (int i = 0; i < 10; i++) {
		cin >> input[i];
	}
	goDice(0);
	cout << ans << '\n';
}