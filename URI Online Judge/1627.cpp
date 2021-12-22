#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    vector<int> time(2), dmg(2);
    int hp;
    cin >> dmg[0] >> time[0] >> dmg[1] >> time[1] >> hp;

    vector<int> hit(2);
    while (1) {
        int player = hit[1] < hit[0];
        hp -= dmg[player];
        if (hp <= 0) {
            cout << (player ? "Beto\n" : "Andre\n");
            return;
        }
        hit[player] += time[player];
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}