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

	int size;
	cin >> size;
	
	int res = 2;
	for (int i = 0; i < size; i++) {
		string s;
		cin >> s;

		res += 1 + (s.find("+") != -1);
	}
	res += res == 13;
		
	cout << res * 100;
}