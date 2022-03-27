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

    int roomCount;
    cin >> roomCount;

    vector<pair<int, int>> rooms(roomCount);
    for (int i = 0; i < rooms.size(); i++) {
        cin >> rooms[i].first;
        rooms[i].second = i;
    }

    sort(rooms.rbegin(), rooms.rend());

    int sum = 0;
    for (int i = 1; i < rooms.size(); i++)
        sum += rooms[i].first;

    if (rooms[0].first <= sum) {
        for (auto &[_, index] : rooms)
            cout << index + 1 << " ";
    } else {
        cout << "impossible";
    }
}