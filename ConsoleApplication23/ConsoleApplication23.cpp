#include "stdafx.h"
#include <iostream>

using namespace std;

const int n = 5, m = 5;

int arr[n][m] = { { 1, 1, 1, 1, 1 },
				{ 0, 0, 0, 0, 1 },
				{ 1, 1, 1, 1, 1 },
				{ 1, 0, 0, 0, 0 } ,
				{ 1, 1, 1, 1, 1,} };

bool f[n][m] = { 0 };

void labyrinth(int i, int j)
{
	if ((j >= 0 && j < n) && (i >= 0 && i < m))
	{
		if (arr[m - 1][n - 1] == 1 && f[m - 1][n - 1] == true)
			return;

		f[i][j] = true;

		if (arr[i][j - 1] == 1 && f[i][j - 1] == false)	labyrinth(i, j - 1);
		if (arr[i][j + 1] == 1 && f[i][j + 1] == false)	labyrinth(i, j + 1);
		if (arr[i - 1][j] == 1 && f[i - 1][j] == false)	labyrinth(i - 1, j);
		if (arr[i + 1][j] == 1 && f[i + 1][j] == false) labyrinth(i + 1, j);

	}

}

void res(int i, int j) {

	if (arr[n - 1][m - 1] != 0 && arr[0][0] != 0 ) {

		labyrinth(i, j);
		(f[n - 1][m - 1] == true) ? cout << "true " << endl : cout << "false" << endl;
	}
	else cout << "false" << endl;
}

int main()

{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl;
	res(0, 0);

	return 0;

}