#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<long long> prepare() {
    vector<long long> a = { 0, 1 };
    for (int i = 2; i < 17; i++)
        a.push_back(i % 2 ? a[i - 2] * a[i - 1] : a[i - 2] + a[i - 1]);
    return a;
}

bool solve() {
    int n;
    if (!(cin >> n))
        return 0;

    static vector<long long> a = prepare();

    cout << a[n - 1] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}