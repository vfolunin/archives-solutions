#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool ask(string &move) {
	cout << move << endl;

	string ans;
	cin >> ans;

	return ans == "EMPTY";
}

void dfs(int y, int x, int backD) {
	static set<pair<int, int>> visited;
	visited.insert({ y, x });

	static vector<int> dy = { 1, 0, -1, 0 };
	static vector<int> dx = { 0, -1, 0, 1 };
	static vector<string> dMove = { "SOUTH", "WEST", "NORTH", "EAST" };

	for (int d = 0; d < dy.size(); d++) {
		int ty = y + dy[d], tx = x + dx[d];
		if (!visited.count({ ty, tx }) && ask(dMove[d]))
			dfs(ty, tx, (d + 2) % dy.size());
	}

	if (backD != -1)
		ask(dMove[backD]);
	else
		cout << "DONE" << endl;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
 
	dfs(0, 0, -1);
}