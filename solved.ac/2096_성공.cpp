/*


#include <iostream>
#include <algorithm>

using namespace std;

int index[100000][3];
int index_max[2][3];
int index_min[2][3];


int main()
{
	int size = 0, answer_max = 0, answer_min = 100;

	cin >> size;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> index[i][j];
		}
	}


	index_max[0][0] = index[0][0]; index_min[0][0] = index[0][0];
	index_max[0][1] = index[0][1]; index_min[0][1] = index[0][1];
	index_max[0][2] = index[0][2]; index_min[0][2] = index[0][2];

	answer_max = max(max(index_max[0][0], index_max[0][1]), index_max[0][2]);
	answer_min = min(min(index_min[0][0], index_min[0][1]), index_min[0][2]);

	for (int i = 1; i < size; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (j == 0)
			{
				index_max[1][j] = index[i][j] + 
					max(index_max[0][j], index_max[0][j + 1]);

				index_min[1][j] = index[i][j] +
					min(index_min[0][j], index_min[0][j + 1]);
			}

			else if (j == 1)
			{
				index_max[1][j] = index[i][j] +
					max(max(index_max[0][j], index_max[0][j - 1]),
						index_max[0][j + 1]);

				index_min[1][j] = index[i][j] +
					min(min(index_min[0][j], index_min[0][j - 1]),
						index_min[0][j + 1]);
			}

			else if (j == 2)
			{
				index_max[1][j] = index[i][j] +
					max(index_max[0][j], index_max[0][j - 1]);

				index_min[1][j] = index[i][j] +
					min(index_min[0][j], index_min[0][j - 1]);
			}

		}

		for (int k = 0; k < 3; k++)
		{
			index_max[0][k] = index_max[1][k];
			index_min[0][k] = index_min[1][k];
		}

		answer_max = max(max(index_max[0][0], index_max[0][1]), index_max[0][2]);
		answer_min = min(min(index_min[0][0], index_min[0][1]), index_min[0][2]);

	}

	cout << answer_max << " " << answer_min;
}

*/