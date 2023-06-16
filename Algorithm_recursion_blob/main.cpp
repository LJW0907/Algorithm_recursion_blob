#include <iostream>

#define N 8
#define CELL 0
#define IMAGE 1
#define ALREADY 2

using namespace std;

int grid[N][N] = {
	{0, 0, 0, 0, 0, 0, 0, 1},
	{0, 1, 1, 0, 1, 1, 0, 1},
	{0, 0, 0, 1, 0, 0, 0, 1},
	{0, 1, 0, 0, 1, 1, 0, 0},
	{0, 1, 1, 1, 0, 0, 1, 1},
	{0, 1, 0, 0, 0, 1, 0, 1},
	{0, 0, 0, 1, 0, 0, 0, 1},
	{0, 1, 1, 1, 0, 1, 0, 0},
};

int countCells(int x, int y) {
	int result;

	if (x < 0 || x >= N || y < 0 || y >= N)
		return 0;
	else if (grid[x][y] != IMAGE)
		return 0;
	else {
		grid[x][y] = ALREADY;
		return 1 + countCells(x - 1, y + 1) + countCells(x, y + 1)
			+ countCells(x + 1, y + 1) + countCells(x + 1, y)
			+ countCells(x + 1, y - 1) + countCells(x, y - 1)
			+ countCells(x - 1, y - 1) + countCells(x - 1, y);
	}
}

void printMaze() {
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			if (grid[x][y] == CELL)
				cout << "бр\t";
			else if (grid[x][y] == IMAGE)
				cout << "бс\t";
			else if (grid[x][y] == ALREADY)
				cout << "X\t";
		}
		cout << endl;
	}
}

int main() {
	int result;

	printMaze();

	cout << endl;

	result = countCells(0, 0);
	printMaze();
	cout << result << endl;
}