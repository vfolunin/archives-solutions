#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int flatNumber, flatsPerFloor;
    cin >> flatNumber >> flatsPerFloor;

    if (flatNumber <= 2)
        cout << "1\n";
    else
        cout << 2 + (flatNumber - 3) / flatsPerFloor << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}