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

    vector<string> a;
    for (string s; cin >> s; )
        a.push_back(s);

    vector<vector<long long>> ways(a.size(), vector<long long>((a[0].size() + 1) / 2));
    ways[0][0] = 1;

    for (int y = 0; y < ways.size(); y++) {
        for (int x = 0; x < ways[0].size(); x++) {
            if (a[y][x * 2] == '0')
                continue;
            if (y)
                ways[y][x] += ways[y - 1][x];
            if (x)
                ways[y][x] += ways[y][x - 1];
        }
    }

    cout << ways.back().back();
}