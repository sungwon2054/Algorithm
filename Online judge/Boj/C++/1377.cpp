#include <iostream>
#include <map>
#include <algorithm>
#define endl '\n'

using namespace std;

map<int, int > m;
int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	int idx = 1;
	for (int i = 1; i <= n; i++) {
		int input_num;
		cin >> input_num;
		v.push_back({ input_num, idx });
		idx++;
	}
	pre_v = v;
	sort(v.begin(), v.end());

	int index_distance = 0;
	for (int i = 0; i < v.size(); i++) {
		index_distance = max(v[i].second - pre_v[i].second, index_distance);
	}
	
	cout << index_distance + 1 << endl;
}