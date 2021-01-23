#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> prepare() {
    vector<int> v = { 0, 1, 2 };
    for (int i = 3; i <= 5e5; i++)
        v.push_back(i < v[i - 1] + 2 ? 2 : v[i - 1] + 2);
    return v;
}

bool solve() {
    int n;
    cin >> n;

    if (!n)
        return 0;

    static vector<int> v = prepare();
    cout << v[n] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}