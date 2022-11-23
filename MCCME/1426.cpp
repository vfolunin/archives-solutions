#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int h, w;
    cin >> h >> w;

    multiset<int> seats;
    for (int i = 0; i < h * w; i++) {
        int seat;
        cin >> seat;
        seats.insert(seat);
    }

    int massCount;
    cin >> massCount;

    vector<int> masses(massCount);
    for (int &mass : masses)
        cin >> mass;

    sort(masses.begin(), masses.end());
    int res = 0;

    for (int &mass : masses) {
        auto it = seats.lower_bound(mass);
        if (it == seats.end())
            break;
        seats.erase(it);
        res++;
    }

    cout << res;
}