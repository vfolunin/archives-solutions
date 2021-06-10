#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int length;
    cin >> length;
    length *= 100;

    vector<int> cars;
    while (1) {
        int car;
        cin >> car;

        if (!car)
            break;

        cars.push_back(car);
    }

    vector<vector<int>> minB(cars.size() + 1, vector<int>(length + 1, 1e9));
    vector<vector<int>> side(cars.size() + 1, vector<int>(length + 1));
    minB[0][0] = 0;

    for (int i = 0; i < cars.size(); i++) {
        for (int a = 0; a <= length; a++) {
            if (minB[i][a] == 1e9)
                continue;

            if (a + cars[i] <= length && minB[i + 1][a + cars[i]] > minB[i][a]) {
                minB[i + 1][a + cars[i]] = minB[i][a];
                side[i + 1][a + cars[i]] = 1;
            }

            if (minB[i][a] + cars[i] <= length && minB[i + 1][a] > minB[i][a] + cars[i]) {
                minB[i + 1][a] = minB[i][a] + cars[i];
                side[i + 1][a] = 2;
            }
        }
    }

    int i = cars.size(), a;
    while (1) {
        a = min_element(minB[i].begin(), minB[i].end()) - minB[i].begin();
        if (minB[i][a] != 1e9)
            break;
        i--;
    }

    vector<string> res(i);
    for (; i; i--) {
        if (side[i][a] == 1) {
            res[i - 1] = "port";
            a -= cars[i - 1];
        } else {
            res[i - 1] = "starboard";
        }
    }

    if (test)
        cout << "\n";
    cout << res.size() << "\n";
    for (string &side : res)
        cout << side << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve(i);
}