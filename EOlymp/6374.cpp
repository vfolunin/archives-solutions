#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int h, m;
    cin >> h >> m;

    int t = (h * 60 + m + 24 * 60 - 45) % (24 * 60);

    cout << "Case #" << test << ": " << t / 60 << " " << t % 60 << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 1; test <= testCount; test++)
        solve(test);
}