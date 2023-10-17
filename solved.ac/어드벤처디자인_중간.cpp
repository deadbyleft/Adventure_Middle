
/*

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//int now = 0;

// visited에 저장된 값은 바로 node[current].second == true 처리한다.
// visited에 동일한 값이 들어간다면 사이클 조건이 충족되었음을 알 수 있다.


void dfs(int current, vector <pair <int, bool>>& node, vector <pair <int, int>>& connected, vector<int>& visited
	, vector<int>& cycle, vector<bool>& node_used)
{
	bool same = false;

	int cycle_length = 0;

	static vector <pair <int, int>> t_size;

	if (node_used[current] == true)
		return;

	visited.push_back(current);

	for (int i = 0; i < visited.size(); i++)
		cout << visited[i] << " ";

	cout << endl;

	for (int i = 0; i < visited.size() - 1; i++)
	{
		if (current == visited[i])
			same = true;

		if (same == true)
		{
			cycle.push_back(visited[i]);
			cycle_length++;
		}
			
	}

	if (cycle_length == 2)
	{
		t_size.push_back(make_pair(current, visited[visited.size() - 2]));
	}

	for (int i = 0; i < t_size.size(); i++)
	{
		if (current == t_size[i].second && visited[visited.size() - 2 == t_size[i].first] ||
			current == t_size[i].first && visited[visited.size() - 2 == t_size[i].second])
			return;

		cout<< " [ " << t_size[i].first << ", " << t_size[i].second << " ] ";
	}
	
	cout << '\n';

	if (same == true)
	{
		cycle.push_back(current);
		cycle.push_back(-1);
		same = false;

		return;
	}

	if (node[current].second == false) // 아직 방문된 적 없다면
		node[current].second = true;

	for (int i = 0; i < connected.size(); i++) // 해당 노드가 연결된 값이 있는지 확인
	{
		if (connected[i].first == current) // 연결된 노드가 있다면
		{
			dfs(connected[i].second, node, connected, visited, cycle, node_used);

			if (node_used[connected[i].second] == false)
				visited.pop_back();
		}

	}

}

int set_node(vector <pair <int, bool>>& node, vector<bool>& node_used)
{
	int node_num = 0;

	cout << "노드의 개수를 입력하시오 : ";
	cin >> node_num;

	for (int i = 0; i < node_num; i++) // node_num 만큼 노드를 생성한다
	{
		node_used.push_back(false);
		node.push_back(make_pair(i, false));
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

	return connected_num;
}

void cal_cycle(int node_num, vector <pair <int, bool>>& node,
	vector <pair <int, int>>& connected, vector<int>& visited, vector<int>& cycle
	, vector<bool>& node_used)
{
	for (int i = 0; i < node_num; i++)
	{
		if (node[i].second == false)
		{
			dfs(i, node, connected, visited, cycle, node_used);
			visited.pop_back();

			for (int i = 0; i < node.size(); i++)
			{
				if (node[i].second == true)
					node_used[i] = true;
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
	vector <pair <int, bool>> node; // node값 + 방문여부
	vector <pair <int, int>> connected;

	vector<bool> node_used;
	vector<int> visited;
	vector<int> cycle;

	int node_num = set_node(node, node_used);
	int connected_num = set_connected(connected);

	cal_cycle(node_num, node, connected, visited, cycle, node_used);
	print_result(cycle);

	return 0;
}

*/