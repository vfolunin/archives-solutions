#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int hp, dmg, hitTime, reloadTime;
    cin >> hp >> dmg >> hitTime >> reloadTime;

    int hitCount = (hp + dmg - 1) / dmg;
    cout << hitCount * hitTime + (hitCount - 1) * reloadTime;
}