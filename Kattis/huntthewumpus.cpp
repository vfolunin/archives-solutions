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

    int seed;
    cin >> seed;

    vector<int> a(4, -1);
    for (int &value : a) {
        do {
            seed += seed / 13 + 15;
        } while (count(a.begin(), a.end(), seed % 100));
        value = seed % 100;
    }

    for (int i = 1, guess; cin >> guess; i++) {
        auto it = find(a.begin(), a.end(), guess);
        if (it != a.end()) {
            cout << "You hit a wumpus!\n";
            *it = -1;
        }

        int dist = 1e9;
        for (int value : a)
            if (value != -1)
                dist = min(dist, abs(value / 10 - guess / 10) + abs(value % 10 - guess % 10));

        if (dist == 1e9) {
            cout << "Your score is " << i << " moves.\n";
            break;
        } else {
            cout << dist << "\n";
        }
    }
}