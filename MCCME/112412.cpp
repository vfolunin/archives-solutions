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

    int l, r, goalTarget, playerCount;
    cin >> l >> r >> goalTarget >> playerCount;

    int resCount = 0;
    for (int i = 0; i < playerCount; i++) {
        string surname, name;
        int year, goalCount;
        cin >> surname >> name >> year >> goalCount;

        if (l <= year && year <= r && goalCount == goalTarget) {
            cout << surname << " " << name << "\n";
            resCount++;
        }
    }

    cout << resCount;
}