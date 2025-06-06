#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int t;
    cin >> t;

    t = (9 * 60 + t) % (24 * 60);

    cout << "Scenario #" << test << ": ";
    cout << setw(2) << setfill('0') << t / 60 << ":";
    cout << setw(2) << setfill('0') << t % 60 << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 1; test <= testCount; test++)
        solve(test);
}