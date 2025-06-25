// malko pseudo code ama ayde

#include <iostream>
#include <vector>
using namespace std;

struct Area {
	int sum;
	int count;
	vector<pair<int, int>> points;
};

void dfs(int matrix[1000][1000], int r, int c, int i, int j, Area& area) {
	if (i < 0 || i >= r || j < 0 || j >= c || matrix[i][j] == 0) {
		return;
	}

	area.sum += matrix[i][j];
	area.count++;
	area.points.push_back({ i, j });
	matrix[i][j] = 0; // Mark as visited

	dfs(matrix, r, c, i - 1, j, area);
	dfs(matrix, r, c, i, j - 1, area);
	dfs(matrix, r, c, i, j + 1, area);
	dfs(matrix, r, c, i + 1, j, area);
	
	dfs(matrix, r, c, i + 1, j + 1, area);
	dfs(matrix, r, c, i + 1, j - 1, area);
	dfs(matrix, r, c, i - 1, j + 1, area);
	dfs(matrix, r, c, i - 1, j - 1, area);
}

std::vector<Area> getAreas(int matrix[1000][1000], int r, int c) {
	std::vector<Area> areas;

	for (size_t i = 0; i < r; i++) {
		for (size_t j = 0; j < c; j++) {
			if (matrix[i][j] != 0) {
				Area area = { 0, 0 };
				dfs(matrix, r, c, i, j, area);
				areas.push_back(area);
			}
		}
	}

	return areas;
}

int main() {
	int r, c;
	int matrix[1000][1000];
	std::vector<Area> areas = getAreas(matrix, r, c);
}
