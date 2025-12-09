#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int w, h;
	cin >> w >> h;

	vector<string> a(h);

	vector<string> types = { "ROPB", "YOGB", "UGPB" };
	vector<int> res(types.size());
	for (int y = 0; y < h; y++) {
		cin >> a[y];
		for (int x = 0; x < w; x++)
			for (int i = 0; i < types.size(); i++)
				res[i] += types[i].find(a[y][x]) != -1 && (!x || types[i].find(a[y][x - 1]) == -1);
	}

	for (int value : res)
		cout << value << " ";
}