#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<long long> getFib() {
    vector<long long> res = { 1, 1 };
    for (int i = 2; res.size() < 46; i++)
        res.push_back(res[i - 2] + res[i - 1]);
    return res;
}

char getChar(int level, int index) {
    if (level <= 1)
        return 'a' + level;

    static vector<long long> fib = getFib();
    if (index < fib[level - 2])
        return getChar(level - 2, index);
    else
        return getChar(level - 1, index - fib[level - 2]);
}

void solve() {
    int level, index;
    cin >> level >> index;
    index--;

    cout << getChar(level, index) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}