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

    int totalDist, dist, stopCount;
    cin >> totalDist >> dist >> stopCount;

    vector<int> stops(stopCount);
    for (int &stop : stops)
        cin >> stop;
    stops.push_back(totalDist);

    int last = 0, res = 0;
    for (int i = 0; i < stops.size(); i++) {
        if (stops[i] - last > dist) {
            if (!i || stops[i] - stops[i - 1] > dist) {
                cout << -1;
                return 0;
            }
            last = stops[i - 1];
            res++;
        }
    }

    cout << res;
}