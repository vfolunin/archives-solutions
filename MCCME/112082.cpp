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

    int size;
    cin >> size;

    vector<pair<int, int>> coords(size);
    int res = 0;

    for (int i = 0; i < coords.size(); i++) {
        int y;
        cin >> y;
        y--;

        coords[i] = { i, y };

        for (int j = 0; j < i; j++)
            res += coords[i].first + coords[i].second == coords[j].first + coords[j].second ||
                   coords[i].first - coords[i].second == coords[j].first - coords[j].second;
    }

    cout << res;
}