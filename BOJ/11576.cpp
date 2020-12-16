#include <iostream>
#include <stack>
#include <math.h>
using namespace std;

int main() {
	//�Է� ó��
	int a, b, m;
	cin >> a >> b;
	cin >> m;

	//10���� ��ȯ �� ����
	int to_dec = 0;
	
	//a���� -> 10����
	while (m--) {
		int num;
		cin >> num;
		to_dec += num*pow(a, m);
	}

	//������ stack�� ����: 10���� -> b���� ��ȯ�� b^0, b^1, b^2 .. �� �ش��ϴ� ������ ��ȯ��
	stack<int> ans;

	//�ӽ� ���� div
	int div = to_dec;

	//10���� -> b����
	while (div) {
		ans.push(div % b);
		div /= b;		
	}

	//stack�� �ִ� �� �ϳ��� ���
	while (!ans.empty()) {
		cout << ans.top() << " ";
		ans.pop();
	}

	return 0;
}