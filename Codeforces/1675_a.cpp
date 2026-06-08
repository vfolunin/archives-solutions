#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int haveA, haveB, haveAB, needA, needB;
    cin >> haveA >> haveB >> haveAB >> needA >> needB;

    needA = max(0, needA - haveA);
    needB = max(0, needB - haveB);
    cout << (needA + needB <= haveAB ? "YES\n" : "NO\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}