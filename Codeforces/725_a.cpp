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

	string s;
	cin >> s >> s;

	int res = 0;
	for (int i = 0; i < s.size() && s[i] == '<'; i++)
		res++;
	for (int i = s.size() - 1; i >= 0 && s[i] == '>'; i--)
		res++;

	cout << res;
}