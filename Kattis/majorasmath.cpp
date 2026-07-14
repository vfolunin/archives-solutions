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

    int hp, arrowCount;
    cin >> hp >> arrowCount;

    map<string, int> dmg;
    cin >> dmg["standard"] >> dmg["fire"] >> dmg["ice"] >> dmg["light"];

    for (int i = 0; i < arrowCount; i++) {
        string type;
        cin >> type;

        hp -= dmg[type];
    }

    if (hp <= 0)
        cout << "dead";
    else
        cout << hp;
}