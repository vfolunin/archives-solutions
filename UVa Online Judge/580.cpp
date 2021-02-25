#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<long long> prepare() {
    vector<long long> v(31);
    v[0] = 1;
    v[1] = 2;
    v[2] = 4;
    for (int i = 3; i < v.size(); i++)
        v[i] = v[i - 1] + v[i - 2] + v[i - 3];
    return v;
}

bool solve() {
    int n;
    cin >> n;

    if (!n)
        return 0;

    static vector<long long> v = prepare();

    cout << (1LL << n) - v[n] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}