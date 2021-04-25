#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int n;
    if (!(cin >> n))
        return 0;

    vector<long long> width(3);
    for (int i = 0; i < n; i++) {
        long long w;
        cin >> w;
        width[i % 3] += w;
    }

    vector<long long> res(3);

    for (int i = 0; i < n; i++) {
        long long height;
        cin >> height;

        for (int j = 0; j < 3; j++)
            res[(i + j) % 3] += height * width[j];
    }

    for (int i = 0; i < 3; i++)
        cout << res[(i + 1) % 3] << (i < 2 ? " " : "\n");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}