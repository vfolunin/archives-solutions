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

    vector<string> a(size);
    for (string &s : a)
        cin >> s;

    int res = 0;
    for (int i = 0; i + 1 < a.size(); i++)
        res += abs(a[i][0] - a[i + 1][0]) + abs(a[i][1] - a[i + 1][1]);

    cout << res;
}