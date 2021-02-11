#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int simulate(int n, int m) {
    vector<int> cities(n);
    for (int i = 0; i < n; i++)
        cities[i] = i + 1;

    int index = 0;
    while (cities.size() > 1) {
        cities.erase(cities.begin() + index);
        index = (index - 1 + cities.size() + m) % cities.size();
    }

    return cities[0];
}

vector<int> prepare() {
    vector<int> res(150);
    for (int n = 2; n < res.size(); n++) {
        res[n] = 2;
        while (simulate(n, res[n]) != 2)
            res[n]++;
    }
    return res;
}

bool solve() {
    int n;
    cin >> n;

    if (!n)
        return 0;

    static vector<int> res = prepare();
    cout << res[n] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}