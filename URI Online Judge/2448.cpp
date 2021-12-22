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

    int houseCount, orderCount;
    cin >> houseCount >> orderCount;

    map<int, int> housePos;
    for (int i = 0; i < houseCount; i++) {
        int house;
        cin >> house;
        housePos[house] = i;
    }

    long long time = 0;
    int pos = 0;

    for (int i = 0; i < orderCount; i++) {
        int house;
        cin >> house;
        time += abs(pos - housePos[house]);
        pos = housePos[house];
    }

    cout << time << "\n";
}