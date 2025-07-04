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

    int n, p;
    cin >> n >> p;

    string pattern = to_string(1 << p);
    int res = 0;

    for (int i = 1; i <= n; i++)
        res += to_string(i).find(pattern) != -1;

    cout << res;
}