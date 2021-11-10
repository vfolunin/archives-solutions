#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int raceCount, carCount;
    cin >> raceCount >> carCount;

    if (!raceCount)
        return 0;

    vector<vector<int>> raceResult(raceCount, vector<int>(carCount));
    for (vector<int> &result : raceResult)
        for (int &x : result)
            cin >> x;

    int scoreCount;
    cin >> scoreCount;

    for (int i = 0; i < scoreCount; i++) {
        int placeCount;
        cin >> placeCount;

        vector<int> placePoints(placeCount);
        for (int &x : placePoints)
            cin >> x;

        vector<int> carPoints(carCount);
        for (vector<int> &result : raceResult)
            for (int carIndex = 0; carIndex < carCount; carIndex++)
                if (result[carIndex] <= placeCount)
                    carPoints[carIndex] += placePoints[result[carIndex] - 1];

        vector<int> winners = { 0 };
        for (int carIndex = 1; carIndex < carCount; carIndex++) {
            if (carPoints[winners[0]] < carPoints[carIndex])
                winners = { carIndex };
            else if (carPoints[winners[0]] == carPoints[carIndex])
                winners.push_back(carIndex);
        }

        for (int j = 0; j < winners.size(); j++)
            cout << winners[j] + 1 << (j + 1 < winners.size() ? ' ' : '\n');
    }

    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}