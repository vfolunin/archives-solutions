#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isLucky(int n) {
	return to_string(n).find('8') != -1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    int res = 1;
    while (!isLucky(n + res))
        res++;

    cout << res;
}