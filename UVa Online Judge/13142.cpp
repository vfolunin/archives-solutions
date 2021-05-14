#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    long long time, velocity, distance;
    cin >> time >> velocity >> distance;

    time *= 24 * 60 * 60;
    distance *= 1000;
    int speed = distance * 1000 / time;

    if (speed > 0)
        cout << "Remove " << speed << " tons\n";
    else
        cout << "Add " << -speed << " tons\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}