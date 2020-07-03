#include <iostream>
#include <vector>

using namespace std;

int N, M, K;
int ans;
vector<int> party[51];
vector<int> know_truth;
int people[51];

int Find(int n) {
	if (people[n] == n) return n;
	else return people[n] = Find(people[n]);
}

bool Same_root(int n1, int n2) {
	n1 = Find(n1);
	n2 = Find(n2);
	if (n1 == n2) return true;
	else return false;
}

void Solve_problem() {
	for (int i = 0; i < M; i++) {
		bool flag = false;
		for (int j = 0; j < party[i].size(); j++) {
			int value = party[i][j];
			for (int k = 0; k < know_truth.size(); k++) {
				if (Same_root(value, know_truth[k])) {
					flag = true;
					break;
				}
			}
			if (flag) {
				ans--;
				break;
			}
		}
	}
}

void Union(int n1, int n2) {
	n1 = Find(n1);
	n2 = Find(n2);
	people[n2] = n1;
}

void Union_root() {
	for (int i = 0; i < M; i++) {
		int N1 = party[i][0];
		for (int j = 1; j < party[i].size(); j++) {
			int N2 = party[i][j];
			Union(N1, N2);
		}
	}
}

void Init_root() {
	for (int i = 1; i <= N; i++) {
		people[i] = i;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	cin >> K;
	for (int i = 0; i < K; i++) {
		int n;
		cin >> n;
		know_truth.push_back(n);
	}
	for (int i = 0; i < M; i++) {
		int n;
		cin >> n;
		for (int j = 0; j < n; j++) {
			int m; 
			cin >> m;
			party[i].push_back(m);
		}
	}
	ans = M;

	Init_root(); //root 값 초기화
	Union_root(); //root 값 재설정
	Solve_problem();

	cout << ans << '\n';
}