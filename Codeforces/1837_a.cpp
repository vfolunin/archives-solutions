#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int dist, divisor;
    cin >> dist >> divisor;

    if (dist % divisor)
        cout << "1\n" << dist << "\n";
    else
        cout << "2\n1 " << dist - 1 << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}