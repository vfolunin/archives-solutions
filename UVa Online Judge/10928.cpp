#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> bestPlaces;
    int bestNeighbors = 1e9;

    for (int i = 0; i < n; i++) {
        int neighbors = 0;
        do {
            int x;
            cin >> x;
            neighbors++;
        } while (cin.get() == ' ');

        if (neighbors < bestNeighbors) {
            bestPlaces.assign(1, i);
            bestNeighbors = neighbors;
        } else if (neighbors == bestNeighbors) {
            bestPlaces.push_back(i);
        }
    }

    for (int i = 0; i < bestPlaces.size(); i++)
        cout << bestPlaces[i] + 1 << (i + 1 < bestPlaces.size() ? ' ' : '\n');
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}