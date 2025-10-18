#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<vector<int>> a(4, vector<int>(4));
    for (int y = 0; y < a.size(); y++)
        for (int x = 0; x < a.size(); x++)
            cin >> a[y][x];

    unordered_set<int> sums;

    for (int y = 0; y < a.size(); y++) {
        int sum = 0;
        for (int x = 0; x < a.size(); x++)
            sum += a[y][x];
        sums.insert(sum);
    }

    for (int x = 0; x < a.size(); x++) {
        int sum = 0;
        for (int y = 0; y < a.size(); y++)
            sum += a[y][x];
        sums.insert(sum);
    }

    cout << (sums.size() == 1 ? "magic\n" : "not magic\n");
}