#include <iostream>
#include <vector>
using namespace std;

int main() {
	int a, b;//�Է�
	vector<int> v(1000);
	cin >> a >> b;
	int idx = 0;//v�� �ε����� ����
	for (int i = 1;i<=1000; i++) {//�Է� ������ 1000���� �ݺ�
		for (int j = 0; j < i && idx < 1000; j++) {//i�� ����ŭ v�� �߰�, �� idx�� �Է� ������ 1000���� �۾ƾ���
			v[idx++] = i;
		}
	}
	int ans = 0;
	
	//���� ��
	for (int i = a-1; i <= b-1; i++) {
		ans += v[i];
	}

	//���� ���
	cout << ans;
	return 0;
}