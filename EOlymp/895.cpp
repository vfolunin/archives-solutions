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

    int size, targetPlace;
    cin >> size >> targetPlace;

    vector<int> aPlace(size);
    for (int i = 0; i < size; i++) {
        int id;
        cin >> id;
        aPlace[id - 1] = i;
    }

    vector<int> bPlace(size);
    for (int i = 0; i < size; i++) {
        int id;
        cin >> id;
        bPlace[id - 1] = i;
    }

    for (int aThreshold = 0; aThreshold <= size; aThreshold++) {
        vector<int> aPoints(size);
        for (int i = 0; i < size; i++)
            aPoints[i] = i < aThreshold ? 400 - i : size - i;

        for (int bThreshold = 0; bThreshold <= size; bThreshold++) {
            vector<int> bPoints(size);
            for (int i = 0; i < size; i++)
                bPoints[i] = i < bThreshold ? 400 - i : size - i;

            int place = 1;
            for (int i = 1; i < size; i++)
                place += aPoints[aPlace[0]] + bPoints[bPlace[0]] < aPoints[aPlace[i]] + bPoints[bPlace[i]];

            if (place == targetPlace) {
                cout << "Possible\n";
                for (int points : aPoints)
                    cout << points << " ";
                cout << "\n";
                for (int points : bPoints)
                    cout << points << " ";
                return 0;
            }
        }
    }

    cout << "Impossible";
}