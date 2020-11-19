#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <queue>

#define endl '\n'

using namespace std;

int N;
priority_queue<int, vector<int>, greater<int> > pq_min;
priority_queue<int> pq_max;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N;

	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;

		if (pq_max.empty() || pq_max.top() >= n) {
			pq_max.push(n);
			if (pq_max.size() > pq_min.size() + 1) {
				pq_min.push(pq_max.top());
				pq_max.pop();
			}
		}
		else if (pq_min.empty() || pq_min.top() < n) {
			pq_min.push(n);
			if (pq_min.size() > pq_max.size()) {
				pq_max.push(pq_min.top());
				pq_min.pop();
			}
		}
		else if (pq_max.size() <= pq_min.size()) {
			pq_max.push(n);
		}
		else {
			pq_min.push(n);
		}
		cout << pq_max.top() << endl;
	}
}