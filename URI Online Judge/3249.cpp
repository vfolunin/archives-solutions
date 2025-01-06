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

    int battleCount;
    cin >> battleCount;

    int winCount = 0;
    for (int i = 0; i < battleCount; i++) {
        string battle;
        cin >> battle;
        winCount += battle.find("CD") == -1;
    }

    cout << winCount << "\n";
}