#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'

using namespace std;

int N, ans;

void dfs(vector<int> energy, int sum) {
	if (energy.size() == 2) {
		ans = max(ans, sum);
		return;
	}
	for (int i = 1; i < energy.size() - 1; i++) {
		int num = energy[i];
		sum += energy[i - 1] * energy[i + 1];
		energy.erase(energy.begin() + i);
		dfs(energy, sum);
		energy.insert(energy.begin() + i, num);
		sum -= energy[i - 1] * energy[i + 1];
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	vector<int> v;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		v.push_back(n);
	}

	dfs(v, 0);
	cout << ans << endl;
}