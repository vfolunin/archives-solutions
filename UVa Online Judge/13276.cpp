#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    long long initHp, ammoDmg, ammo, regen;
    cin >> initHp >> ammoDmg >> ammo >> regen;

    long long dmg = ammoDmg * ammo;
    long long hp = max(0LL, initHp - dmg);

    cout << "Case " << test << ": ";
    if (initHp <= dmg) {
        cout << (initHp + ammoDmg - 1) / ammoDmg << "\n";
    } else if (hp && dmg <= regen) {
        cout << "-1\n";
    } else {
        long long cycles = (hp + dmg - regen - 1) / (dmg - regen);
        long long lastHp = initHp - (dmg - regen) * cycles;
        cout << cycles * ammo + (lastHp + ammoDmg - 1) / ammoDmg << "\n";
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}