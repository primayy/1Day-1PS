#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int t;
	cin >> t;
	//t번 테스트를 진행
	while (t--)
	{
		int k;			   //k개의 챕터
		long long ans = 0; //정답의 범위를 고려해서 long long으로 선언해야함
		cin >> k;
		priority_queue<long long, vector<long long>, greater<long long>> pq; //최소힙
																			 //최소힙에 값 삽입
		while (k--)
		{
			int num;
			cin >> num;
			pq.push(num);
		}

		//허프만 인코딩
		while (!pq.empty())
		{
			if (pq.size() == 1)
				break; //하나의 파일이 남으면 멈춤
			long long first = pq.top();
			pq.pop(); //가장 크기가 작은 챕터를 선택한 뒤, 큐에서 pop
			long long second = pq.top();
			pq.pop();				 //다음으로 크기가 작은 챕터를 선택한 뒤, 큐에서 pop
			ans += first + second;	 // 두 챕터의 비용을 더함
			pq.push(first + second); // 두 챕터의 비용을 큐에 다시 삽입
		}
		pq.pop();
		cout << ans << '\n';
	}

	return 0;
}