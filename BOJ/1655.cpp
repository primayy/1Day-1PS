#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	priority_queue<int, vector<int>, less<int>> max_pq;//max heap
	priority_queue<int, vector<int>, greater<int>> min_pq;//min heap
	for (int i = 0; i < n;i++) {
		int num;
		cin >> num;
		if (max_pq.empty()) {
			max_pq.push(num);
		}
		else if (max_pq.size() == min_pq.size()) {//Â¦¼ö °³
			max_pq.push(num);
		}
		else {//È¦¼ö °³
			min_pq.push(num);
		}

		if (!max_pq.empty() && !min_pq.empty() && (max_pq.top() > min_pq.top())) {
			int max_tmp = max_pq.top();
			int min_tmp = min_pq.top();
			max_pq.pop();
			min_pq.pop();
			max_pq.push(min_tmp);
			min_pq.push(max_tmp);
		}
		cout << max_pq.top() << '\n';
	}
}