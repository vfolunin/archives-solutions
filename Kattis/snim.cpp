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

    int takeCount;
    cin >> takeCount;

    vector<int> takes(takeCount);
    for (int &take : takes)
        cin >> take;

    vector<int> grundy(1e4 + 1);
    for (int pileSize = 1; pileSize < grundy.size(); pileSize++) {
        set<int> toGrundy;
        for (int take : takes)
            if (pileSize >= take)
                toGrundy.insert(grundy[pileSize - take]);

        while (toGrundy.count(grundy[pileSize]))
            grundy[pileSize]++;
    }

    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        int size;
        cin >> size;

        int xorSum = 0;
        for (int j = 0; j < size; j++) {
            int pileSize;
            cin >> pileSize;

            xorSum ^= grundy[pileSize];
        }

        cout << (xorSum != 0 ? "W" : "L");
    }
}