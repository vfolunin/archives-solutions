#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int size, distance;
    cin >> size >> distance;

    int res = 0;
    for (int i = 0; i < size; i++) {
        int speed, fuel, consumption;
        cin >> speed >> fuel >> consumption;

        res += distance * consumption <= fuel * speed;
    }

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}