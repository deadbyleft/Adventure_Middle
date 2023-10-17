
/*

#include <iostream>
#include <vector>

using namespace std;

vector<int> index;

void cal(int range, int length, int current_length, int current_num)
{
	if (current_num <= range && current_length < length) // 수열 안 채워졌고 조건 만족시
	{
		index.push_back(current_num);
	}

	if (current_length == length) // 수열 길이 채워졌다면 출력
	{
		for (int i = 0; i < length; i++)
		{
			cout << index[i] << ' ';
		}

		cout << '\n';
		index.pop_back();
		return;
	}

	if (current_num > range) // 수열 조건 불만족시
	{
		index.pop_back();
		return;
	}

	else
	{
		for (int i = current_num; i < range; i++)
			// 현재 길이에서부터 끝까지
		{
			cal(range, length, current_length + 1, i);
		}
	}
	
}

int main()
{
	int range = 0, length = 0;

	cin >> range >> length;

	cal(range, length, 0, 1);


}

*/