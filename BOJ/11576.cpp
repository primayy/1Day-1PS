#include <iostream>
#include <stack>
#include <math.h>
using namespace std;

int main() {
	//입력 처리
	int a, b, m;
	cin >> a >> b;
	cin >> m;

	//10진법 변환 수 저장
	int to_dec = 0;
	
	//a진법 -> 10진법
	while (m--) {
		int num;
		cin >> num;
		to_dec += num*pow(a, m);
	}

	//정답을 stack에 저장: 10진법 -> b진법 변환시 b^0, b^1, b^2 .. 에 해당하는 값부터 변환됨
	stack<int> ans;

	//임시 변수 div
	int div = to_dec;

	//10진법 -> b진법
	while (div) {
		ans.push(div % b);
		div /= b;		
	}

	//stack에 있는 값 하나씩 출력
	while (!ans.empty()) {
		cout << ans.top() << " ";
		ans.pop();
	}

	return 0;
}