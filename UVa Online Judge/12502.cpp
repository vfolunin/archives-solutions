#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    long long timeA, timeB, money;
    cin >> timeA >> timeB >> money;

    timeA *= 3;
    timeB *= 3;

    long long singleTime = (timeA + timeB) / 3;
    timeA -= singleTime;
    timeB -= singleTime;

    cout << max(0LL, money * timeA / (timeA + timeB)) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}