#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using pii = pair<int, int>; //pair<int,int>를 편하게 사용하기 위해

//dr, dc 배열은 가로,세로 방향 방문을 위한 코드를 쉽게 작성하기 위해 사용
int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};
int r, c;
vector<pii> duck_pos;	 //백조의 위치
queue<pii> nxt_duck_pos; //두 백조가 만날 수 있는지 확인하기 위한 큐

//ice_melting은 오늘 녹아서 물로 변한 공간들의 좌표를 반환함
//v는 호수의 상태, points는 물의 좌표
vector<pii> ice_melting(vector<vector<char>> &v, vector<pii> &points)
{
	vector<pii> nxt_melting; //오늘 녹은 물의 좌표는 다음날 녹일 얼음을 찾을 물의 시작좌표가 됨

	for (auto point : points)
	{
		for (int i = 0; i < 4; i++)
		{
			int nr = point.first + dr[i];
			int nc = point.second + dc[i];
			if (nr < 0 || nr >= r || nc < 0 || nc >= c)
				continue;
			if (v[nr][nc] == 'X')
			{									 //물에 인접해 있는 얼음을 찾으면
				v[nr][nc] = '.';				 //물로 바꾸고
				nxt_melting.push_back({nr, nc}); //해당 좌표를 저장
			}
		}
	}

	return nxt_melting;
}

//백조의 만남을 체크, 만나면 true, 못만나면 false 반환
//v는 호수의 상태, q는 nxt_duck_pos, vis는 bfs로 탐색하는 위치의 방문여부를 체크
bool duck_meet_check(vector<vector<char>> &v, queue<pii> &q, vector<vector<bool>> &vis)
{
	queue<pii> tmp_q; //연산을 줄이기 위해 사용하는 임시 큐

	//BFS
	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();
		//백조를 만나면 true 반환
		if (cur.first == duck_pos[1].first && cur.second == duck_pos[1].second)
			return true;
		//4방향 탐색
		for (int i = 0; i < 4; i++)
		{
			int nr = cur.first + dr[i];
			int nc = cur.second + dc[i];
			if (nr < 0 || nr >= r || nc < 0 || nc >= c)
				continue; //범위를 벗어나면 무시
			if (vis[nr][nc])
				continue; //방문한 좌표면 무시
			if (v[nr][nc] == 'X')
			{						  //호수의 상태가 얼음이라면
				tmp_q.push({nr, nc}); //다음날 BFS로 탐색할 위치로 삽입
				vis[nr][nc] = 1;	  //해당 좌표 방문 표시
				continue;
			}
			//방문할 수 있는 좌표 방문
			q.push({nr, nc});
			vis[nr][nc] = 1;
		}
	}
	q = tmp_q; //다음날 탐색할 위치가 저장된 임시 큐를 q(nxt_duck_pos)에 복사
	return false;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> r >> c;
	vector<vector<char>> v;
	vector<pii> water;		  //물의 좌표
	vector<vector<bool>> vis; //백조가 BFS로 방문한 지역 확인을 위한 변수
	for (int i = 0; i < r; i++)
	{
		vector<bool> vis_e(c);
		vis.push_back(vis_e);
	}

	int ans = 0; //정답
				 //입력 처리
	for (int i = 0; i < r; i++)
	{
		string s;
		cin >> s;
		vector<char> v_e(s.size());
		for (int j = 0; j < s.size(); j++)
		{
			if (s[j] == 'L')
				duck_pos.push_back({i, j}); //백조의 좌표 저장
			if (s[j] != 'X')
				water.push_back({i, j}); //물과 백조의 좌표는 물의 좌표로 저장
			v_e[j] = s[j];
		}
		v.push_back(v_e);
	}
	//백조가 BFS 탐색을 시작할 좌표는 첫번째 백조의 좌표
	nxt_duck_pos.push({duck_pos[0].first, duck_pos[0].second});
	vis[duck_pos[0].first][duck_pos[0].second] = 1;

	//문제 풀이
	/*
    1.백조가 만날 수 있는지 확인
    2.얼음을 녹임
    3.ans+1
    */
	while (!duck_meet_check(v, nxt_duck_pos, vis))
	{
		water = ice_melting(v, water);
		ans++;
	}

	cout << ans;
	return 0;
}