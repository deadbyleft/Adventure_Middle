/*


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair <int, int>> connected;
vector<bool> visited;
vector<int> cycle;
vector<int> cycle_saved;

// connected 배열을 이용하여 루트를 확인한다.
// 루트를 visited에 저장 후 cycle이면 벡터 cycle에 저장한다



void dfs(int current)
{
	visited[current] = true; // current번째 노드는 방문됨

	for (int i = 0; i < connected.size(); i++)
	{
		if (connected[i].first == current) // 현재값에서 다른 노드로 갈 수 있을 경우
		{
			for (int i = 0; i < cycle.size(); i++)
			{
				if (connected[i].second == cycle[i]) // 해당 노드 방문으로 사이클이 형성된다면
				{
					for (int i = 0; i < cycle.size(); i++) // 해당 사이클 cycle_saved에 저장
					{
						cycle_saved.push_back(cycle[i]);
					}
					cycle_saved.push_back(-1);
				}
			}

			if (!visited[connected[i].second]) // 연결된 노드값을 방문한 적이 없다면
			{
				cycle.push_back(i); // connected[i] 저장

				dfs(connected[i].second); // 재귀함수 실행
			}				
		}
	}

	if (cycle.size() > 0) // 이 조건문 없다면 오류 (크기가 0이어도 pop 실행되므로)
		cycle.pop_back(); // 다 돌아봤다면 pop
}



int main()
{
	int node_num = 0, cycle_num = 0, connected_num = 0,
		connect_before = 0, connect_after = 0;

	cin >> node_num >> connected_num;

	for (int i = 0; i < node_num; i++)
	{
		visited.push_back(false);
	}	

	for (int i = 0; i < connected_num; i++)
	{
		cin >> connect_before >> connect_after; // 연결된 노드의 값을 입력해준다
		connected.push_back(make_pair(connect_before, connect_after)); // 노드 생성
		
	}

	for (int i = 0; i < node_num; i++)
	{
		dfs(i);
	}

	for (int i = 0; i < cycle_saved.size(); i++)
	{
		if (cycle_saved[i] == -1)
			cout << endl;
		else
		{
			cout << connected[cycle_saved[i]].first << " " <<
				connected[cycle_saved[i]].second << " ";
		}
			
	}


}

*/