#include <iostream>
#include <vector>
using namespace std;

int main() {
	int a, b;//입력
	vector<int> v(1000);
	cin >> a >> b;
	int idx = 0;//v의 인덱스를 저장
	for (int i = 1;i<=1000; i++) {//입력 범위인 1000까지 반복
		for (int j = 0; j < i && idx < 1000; j++) {//i의 값만큼 v에 추가, 단 idx가 입력 범위인 1000보다 작아야함
			v[idx++] = i;
		}
	}
	int ans = 0;
	
	//구간 합
	for (int i = a-1; i <= b-1; i++) {
		ans += v[i];
	}

	//정답 출력
	cout << ans;
	return 0;
}