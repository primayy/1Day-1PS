#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool used[10];
int ans[10];
int tmp_ans = 0;

void backtrack(int start,int end, int k, int n, vector<vector<int>>& v) {
	for (int i = 0; i < n; i++) {
		if (k == n && i == end && v[start][i]!=0) {
			tmp_ans += v[start][i];
			ans[i] = min(ans[i], tmp_ans);
			tmp_ans -= v[start][i];
			return;
		}
		if (used[i] || (v[start][i] == 0)) continue;
		used[i] = 1;
		tmp_ans += v[start][i];
		backtrack(i, end, k+1, n, v);
		used[i] = 0;
		tmp_ans -= v[start][i];
	}
}

int main() {
	//입력 처리
	int n;
	cin >> n;
	vector<vector<int>> v(n);
	for (int i = 0; i < n; i++) {
		vector<int> v_e(n);
		for (int j = 0; j < n; j++) {
			cin >> v_e[j];
		}
		v[i] = v_e;
	}

	//가장 적은 비용을 들이는 외판원의 순회 경로를 구하라
	for (int i = 0; i < n; i++) {
		ans[i] = 987654321;
		tmp_ans = 0;
		used[i] = 1;
		backtrack(i, i, 1, n, v);
		used[0] = 0;
	}
	int answer = 987654321;
	for (auto val : ans) {
		if (val == 0) continue;
		answer = min(answer, val);
	}
	cout << answer;
	return 0;
}