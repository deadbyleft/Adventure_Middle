


#include <iostream>
#include <vector>

using namespace std;

vector<int> index;
vector<int> route;

void dfs(int current)
{
	if (route.size() == 0)
	{
		route.push_back(current);
		return;
	}

	if (route.size() >= 2)
	{
		for (int i = 0; i < route.size() - 1; i++)
		{
			if (current > route.back() && current > route[route.size() - 2])
			{
				for (int j = route.size() - 1; j > i; j--)
				{
					if (current > route[j])
					{
						cout << route[j] << " ";
						route.pop_back();
					}

				}
			}
		}
	}
	

	route.push_back(current);


}

int main()
{
	int num = 0;
	while (cin >> num)
	{
		index.push_back(num);
	}

	for (int i = 0; i < index.size(); i++)
	{
		dfs(index[i]);
	}

	while (!route.empty())
	{
		cout << route.back() << " ";
		route.pop_back();
	}


}


