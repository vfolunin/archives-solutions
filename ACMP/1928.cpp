#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int ask(int i, int j) {
	cout << "? " << i + 1 << " " << j + 1 << endl;
	int ans;
	cin >> ans;
	return ans;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int size;
	cin >> size;

	int ab = ask(0, 1);
	int ac = ask(0, 2);
	int bc = ask(1, 2);

	vector<int> res(size);
	res[0] = (ab + ac - bc) / 2;
	res[1] = ab - res[0];
	res[2] = ac - res[0];

	for (int i = 3; i < res.size(); i++)
		res[i] = ask(0, i) - res[0];

	cout << "! ";
	for (int value : res)
		cout << value << " ";
	cout << endl;
}