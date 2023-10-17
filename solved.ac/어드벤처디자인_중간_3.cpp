
/*

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;



//int now = 0;

// visited에 저장된 값은 바로 index[current].second == true 처리한다.
// visited에 동일한 값이 들어간다면 사이클 조건이 충족되었음을 알 수 있다.




int test(queue<int> cycle_save, vector<int> cycle)
{
	bool define = false;

	if (cycle.size() > cycle_save.size())
	{
		for (int i = 0; i < cycle.size() - cycle_save.size(); i++)
		{
			define = false;

			for (int j = 0; j < cycle_save.size(); j++)
			{			
				if (cycle_save.front() != cycle[i + j])
					define = true;

				cycle_save.push(cycle_save.front());
				cycle_save.pop();
			}

			if (define == false)
				return false;
		}
	}

	return true;
}

void dfs(int current, vector <pair <int, bool>>& index, vector <pair <int, int>>& connected, vector<int>& visited
	, vector<int>& cycle, vector<bool>& index_used, queue<int>& cycle_save)
{
	bool same = false;

	static vector <pair <int, int>> t_size;

	if (index_used[current] == true)
		return;

	visited.push_back(current);

	for (int i = 0; i < visited.size() - 1; i++)
	{
		if (current == visited[i])
			same = true;

		if (same == true)
			cycle_save.push(visited[i]);
	}

	if (same == true)
	{
		if (test(cycle_save, cycle))
		{
			for (int i = cycle_save.size(); i > 0; i--)
			{			
				cycle.push_back(cycle_save.front());
				cycle_save.pop();
			}

			cycle.push_back(current);
			cycle.push_back(-1);
		}

		else
		{
			while (!cycle_save.empty())
				cycle_save.pop();
		}
			

		same = false;
		return;
	}

	if (index[current].second == false) // 아직 방문된 적 없다면
		index[current].second = true;

	for (int i = 0; i < connected.size(); i++) // 해당 노드가 연결된 값이 있는지 확인
	{
		if (connected[i].first == current) // 연결된 노드가 있다면
		{
			dfs(connected[i].second, index, connected, visited, cycle, index_used, cycle_save);

			if (index_used[connected[i].second] == false)
				visited.pop_back();
		}

	}

}



int set_index(vector <pair <int, bool>>& index, vector<bool>& index_used)
{
	int node_num = 0;

	cout << "노드의 개수를 입력하시오 : ";
	cin >> node_num;

	for (int i = 0; i < node_num; i++) // node_num 만큼 노드를 생성한다
	{
		index_used.push_back(false);
		index.push_back(make_pair(i, false));
	}

	return node_num;
}

int set_connected(vector <pair <int, int>>& connected)
{
	int connected_num = 0, connect_before = 0, connect_after = 0;

	cout << "연결된 노드의 개수를 입력하시오 : ";
	cin >> connected_num;

	cout << '\n' << "[ 연결된 노드의 시작과 끝 값을 입력하시오 ] " << '\n' << '\n';

	for (int i = 0; i < connected_num; i++)
	{
		cin >> connect_before >> connect_after; // 연결된 노드의 값을 입력해준다
		connected.push_back(make_pair(connect_before, connect_after)); // 입력값을 바탕으로 연결된 노드값을 생성한다
	}

	sort(connected.begin(), connected.end()); // 연결된 노드의 값을 connected.first 기준으로 오름차순 정렬한다

	return connected_num;
}

void cal_cycle(int node_num, vector <pair <int, bool>>& index,
	vector <pair <int, int>>& connected, vector<int>& visited, vector<int>& cycle
	, vector<bool>& index_used, queue<int>& cycle_save)
{
	for (int i = 0; i < node_num; i++)
	{
		if (index[i].second == false)
		{
			dfs(i, index, connected, visited, cycle, index_used, cycle_save);
			visited.pop_back();

			for (int i = 0; i < index.size(); i++)
			{
				if (index[i].second == true)
					index_used[i] = true;
			}
		}
	}
}

void print_result(vector<int>& cycle)
{
	int cycle_num = 0;

	cout << '\n' << "[ 사이클 목록 ] " << '\n';

	for (int i = 0; i < cycle.size(); i++)
	{
		if (cycle[i] == -1) // 한 사이클이 끝났으면 줄 띄우기
		{
			cout << '\n';
			cycle_num++;
		}
		else
			cout << cycle[i] << " ";
	}

	cout << '\n' << "총 사이클 개수는 " << cycle_num << "개입니다." << '\n';

}

int main()
{
	vector <pair <int, bool>> index; // index값 + 방문여부
	vector <pair <int, int>> connected;

	vector<bool> index_used;
	vector<int> visited;
	vector<int> cycle;
	queue<int> cycle_save;

	int node_num = set_index(index, index_used);
	int connected_num = set_connected(connected);

	cal_cycle(node_num, index, connected, visited, cycle, index_used, cycle_save);
	print_result(cycle);

	return 0;
}




0 2
2 4
4 3
3 1
3 0
4 2
1 3
0 1

0 1
1 2
2 3
3 0
0 2
5 7
7 6
6 4
3 1


*/