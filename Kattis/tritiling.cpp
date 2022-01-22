#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<long long> prepare() {
    vector<long long> v(16);
    v[0] = 1;
    v[1] = 3;
    for (int i = 2; i < v.size(); i++)
        v[i] = 4 * v[i - 1] - v[i - 2];
    return v;
}

bool solve() {
    int n;
    cin >> n;

    if (n < 0)
        return 0;

    static vector<long long> v = prepare();
    if (n % 2)
        cout << "0\n";
    else
        cout << v[n / 2] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}