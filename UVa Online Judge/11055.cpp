#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <random>
using namespace std;

bool solve() {
    int size;
    cin >> size;

    if (!size)
        return 0;

    vector<vector<int>> a(size, vector<int>(size));
    int sum = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            cin >> a[i][j];
        sum += a[i][i];
    }

    vector<int> p(size);
    for (int i = 0; i < size; i++)
        p[i] = i;

    minstd_rand gen;

    for (int i = 0; i < 1000; i++) {
        shuffle(p.begin(), p.end(), gen);

        int curSum = 0;
        for (int i = 0; i < size; i++)
            curSum += a[i][p[i]];

        if (curSum != sum) {
            cout << "not homogeneous\n";
            return 1;
        }
    }

    cout << "homogeneous\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}