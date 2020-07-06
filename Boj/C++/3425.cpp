/*
모든 연산 완료 후(187 line)
st.top() > 1 일때 st.top 을 출력했더니 런타임오류
	st.size() == 0 일때 top을 접근해서

MUL을 수행 할 때 (119 line)
두 수가 곱했을 때 int 범위 초과이므로
int a, int b 
long long mul = a * b
라고 받았지만
a, b도 long long 으로 받아야함
*/
#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#define endl '\n'
const int MAX = 1000000000;
using namespace std;

vector<string> word;
vector<int> word_num;
vector<int> num;

void simul() {
	for (int i = 0; i < num.size(); i++) {
		stack<int> st;
		int word_cnt = 0; //NUM일때 idx 맞추기
		bool flag = false;
		st.push(num[i]);
		for (int j = 0; j < word.size(); j++) {
			if (word[j] == "NUM") {
				if (0 > word_num[word_cnt] || MAX < word_num[word_cnt]) {
					cout << "ERROR" << endl;
					flag = true;
					break;
				}
				st.push(word_num[word_cnt++]);
			}
			else if (word[j] == "POP") {
				if (st.size() == 0) {
					cout << "ERROR" << endl;
					flag = true;
					break;
				}
				st.pop();
			}
			else if (word[j] == "INV") {
				if (st.size() == 0) {
					cout << "ERROR" << endl;
					flag = true;
					break;
				}
				int temp = st.top();
				st.pop();
				st.push(-temp);
			}
			else if (word[j] == "DUP") {
				int temp = st.top();
				st.push(temp);
			}
			else if (word[j] == "SWP") {
				if (st.size() <= 1) {
					cout << "ERROR" << endl;
					flag = true;
					break;
				}
				int temp = st.top();
				st.pop();
				int temp1 = st.top();
				st.pop();
				st.push(temp);
				st.push(temp1);
			}
			else if (word[j] == "ADD") {
				if (st.size() <= 1) {
					cout << "ERROR" << endl;
					flag = true;
					break;
				}
				int temp = st.top();
				st.pop();
				int temp1 = st.top();
				st.pop();
				int num = temp1 + temp;
				if (abs(num) > MAX) {
					cout << "ERROR" << endl;
					flag = true;
					break;
				}
				st.push(temp + temp1);
			}
			else if (word[j] == "SUB") {
				if (st.size() <= 1) {
					cout << "ERROR" << endl;
					flag = true;
					break;
				}
				int temp = st.top();
				st.pop();
				int temp1 = st.top();
				st.pop();
				int num = temp1 - temp;
				if (abs(num) > MAX) {
					cout << "ERROR" << endl;
					flag = true;
					break;
				}
				st.push(temp1 - temp);
			}
			else if (word[j] == "MUL") {
				if (st.size() <= 1) {
					cout << "ERROR" << endl;
					flag = true;
					break;
				}
				long long temp = st.top();
				st.pop();
				long long temp1 = st.top();
				st.pop();
				long long num = temp1 * temp;
				if (abs(num) > MAX) {
					cout << "ERROR" << endl;
					flag = true;
					break;
				}
				st.push(temp * temp1);
			}
			else if (word[j] == "DIV") {
				if (st.size() <= 1) {
					cout << "ERROR" << endl;
					flag = true;
					break;
				}
				int temp = st.top();
				st.pop();
				int temp1 = st.top();
				st.pop();
				
				if (temp == 0) {
					cout << "ERROR" << endl;
					flag = true;
					break;
				}
				int num = abs(temp1) / abs(temp);
				if (abs(num) > MAX) {
					cout << "ERROR" << endl;
					flag = true;
					break;
				}
				if ((temp >= 0 && temp1 < 0) || (temp < 0 && temp1 >= 0)) {
					num = -num;
				}
				st.push(num);
			}
			else if (word[j] == "MOD") {
				if (st.size() <= 1) {
					cout << "ERROR" << endl;
					flag = true;
					break;
				}
				int temp = st.top();
				st.pop();
				int temp1 = st.top();
				st.pop();
				if (temp == 0) {
					cout << "ERROR" << endl;
					flag = true;
					break;
				}
				int num = abs(temp1) % abs(temp);
				if (abs(num) > MAX) {
					cout << "ERROR" << endl;
					flag = true;
					break;
				}
				if (temp1 < 0) {
					num = -num;
				}
				st.push(num);
			}

		}
		if (!flag) {
			if (st.size() == 1) {
				cout << st.top() << endl;
			}
			else {
				cout << "ERROR" << endl;
			}
		}
	}
	cout << endl;
}

void input() {
	while (1) {
		string s;
		int N;
		word.clear();
		word_num.clear();
		num.clear();

		while (1) {
			cin >> s;
			if (s == "END") break;
			if (s == "QUIT") break;

			if (s == "NUM") {
				int n;
				cin >> n;
				word_num.push_back(n);
			}
			word.push_back(s);
		}
		if (s == "QUIT") break;

		cin >> N;
		for (int i = 0; i < N; i++) {
			int n;
			cin >> n;
			num.push_back(n);
		}

		simul();
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	input();
}