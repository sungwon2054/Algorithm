/*
 - 처음에는 1퍼에서 틀렸다. 
   최단거리가 같은 거리일 때, 승객선택시 행과 열을 거꾸로 썼다..

 - 택시가 도착했을 때, 그 자리에서 승객을 태우는 경우 빠트려서 틀림

 - 87퍼에서 택시가 손님을 태우러 못가거나, 태웠지만 목적지에 도착하지 못했을 때,
   map == 0 이고, y != 택시 y위치 && x != 택시 x위치로 했었는데 틀렸고
   chk[y][x] == false 인지로 고쳤더니 맞았다.
*/
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int N, M, K;
int map[21][21];
vector<pair<int, int> > t_start;
vector<pair<int, int> > t_end;
int taxi_y; int taxi_x;
int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0 , 0 };
pair<int, int > choice;
int choice_index;
int ans;
int fuel;

void drive() {
	queue<pair<int, int > >q;
	bool chk[21][21];
	int d_map_z[21][21];
	memset(chk, 0, sizeof(chk));
	memset(d_map_z, 0, sizeof(d_map_z));

	q.push(make_pair(choice.first, choice.second));
	chk[choice.first][choice.second] = true;
	int d_end_y = t_end[choice_index].first;
	int d_end_x = t_end[choice_index].second;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		if (y == d_end_y && x == d_end_x) break;
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (chk[ny][nx]) continue;
			if (map[ny][nx] == 1) continue;
			if (1 <= ny && ny <= N && 1 <= nx && nx <= N) {
				chk[ny][nx] = true;
				q.push(make_pair(ny, nx));
				d_map_z[ny][nx] = d_map_z[y][x] + 1;
			}
		}
	}
	if (chk[d_end_y][d_end_x] == false) {
		ans = -1;
		return;
	}
	K -= d_map_z[d_end_y][d_end_x];
	fuel += d_map_z[d_end_y][d_end_x];
	if (K < 0) {
		ans = -1;
		return;
	}
	t_end.erase(t_end.begin() + choice_index);
	fuel *= 2;
	K += fuel;
	taxi_y = d_end_y;
	taxi_x = d_end_x;
}

void find() {
	queue<pair<int, int > >q;
	bool chk[21][21];
	int q_map_z[21][21];
	memset(chk, 0, sizeof(chk));
	memset(q_map_z, 0, sizeof(q_map_z));

	q.push(make_pair(taxi_y, taxi_x));
	chk[taxi_y][taxi_x] = true;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (chk[ny][nx]) continue;
			if (map[ny][nx] == 1) continue;
			if (1 <= ny && ny <= N && 1 <= nx && nx <= N) {
				chk[ny][nx] = true;
				q.push(make_pair(ny, nx));
				q_map_z[ny][nx] = q_map_z[y][x] + 1;
			}
		}
	}
	int len = t_start.size();
	int index = 0;
	int compare_value_y = t_start[0].first;
	int compare_value_x = t_start[0].second;
	for (int i = 1; i < len; i++) {
		if (q_map_z[t_start[i].first][t_start[i].second] == q_map_z[compare_value_y][compare_value_x]) {
			if (t_start[i].first == compare_value_y) {
				if (t_start[i].second < compare_value_x) {
					compare_value_y = t_start[i].first;
					compare_value_x = t_start[i].second;
					index = i;
				}
			}
			else if (t_start[i].first < compare_value_y) {
				compare_value_y = t_start[i].first;
				compare_value_x = t_start[i].second;
				index = i;
			}
		}
		else if (q_map_z[t_start[i].first][t_start[i].second] < q_map_z[compare_value_y][compare_value_x]) {
			compare_value_y = t_start[i].first;
			compare_value_x = t_start[i].second;
			index = i;
		}
	}
	taxi_y = compare_value_y;
	taxi_x = compare_value_x;
	if (chk[compare_value_y][compare_value_x] == false) {
		ans = -1;
		return;
	}
	K -= q_map_z[compare_value_y][compare_value_x];
	if (K < 0) {
		ans = -1;
		return;
	}
	choice = make_pair(compare_value_y, compare_value_x);
	t_start.erase(t_start.begin() + index);
	choice_index = index;
}

void sol() {
	// M번 일하기
	for (int i = 0; i < M; i++) {
		fuel = 0;
		find(); // 가장 가까운 사람 찾기
		if (ans == -1)
			break;
		drive(); // 운전
		if (ans == -1)
			break;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}
	cin >> taxi_y >> taxi_x;
	for (int i = 0; i < M; i++) {
		int s_y, s_x, e_y, e_x;
		cin >> s_y >> s_x >> e_y >> e_x;
		t_start.push_back(make_pair(s_y, s_x));
		t_end.push_back(make_pair(e_y, e_x));
	}

	sol();
	if (ans == -1)
		cout << ans << '\n';
	else
		cout << K << '\n';
}