#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int n, usedCols, usedDiagsA, usedDiagsB, res;
char board[20][20];

void rec(int row) {
	if (row == n) {
		res++;
		return;
	}
	for (int col = 0; col < n; col++) {
		int da = row + col;
		int db = col - row + n - 1;
		if ((usedCols & (1 << col)) ||
			(usedDiagsA & (1 << da)) ||
			(usedDiagsB & (1 << db)) ||
			board[row][col] != '.')
			continue;

		usedCols |= (1 << col);
		usedDiagsA |= (1 << da);
		usedDiagsB |= (1 << db);

		rec(row + 1);

		usedCols &= ~(1 << col);
		usedDiagsA &= ~(1 << da);
		usedDiagsB &= ~(1 << db);
	}
}


int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	//int testsCount;
	//scanf("%d", &testsCount);
	for (int testN = 1; /*testN <= testsCount*/1; testN++) {

		scanf("%d", &n);
		if (n == 0)
			break;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				scanf(" %c", &board[i][j]);

		res = 0;
		rec(0);
		printf("Case %d: %d\n", testN, res);

	}
}