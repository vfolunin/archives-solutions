#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<long long> prepare() {
    vector<vector<vector<long long>>> ways(31, vector<vector<long long>>(3, vector<long long>(3)));

    for (int a = 0; a < 3; a++)
        ways[1][a][a] = 1;

    for (int a = 0; a < 3; a++)
        for (int b = 0; b < 3; b++)
            ways[2][a][b] = 1;

    for (int size = 3; size < ways.size(); size++)
        for (int a = 0; a < 3; a++)
            for (int b = 0; b < 3; b++)
                for (int c = 0; c < 3; c++)
                    if (a == b || a == c || b == c)
                        ways[size][b][c] += ways[size - 1][a][b];

    vector<long long> res(ways.size());

    for (int size = 0; size < ways.size(); size++)
        for (int a = 0; a < 3; a++)
            for (int b = 0; b < 3; b++)
                res[size] += ways[size][a][b];

    return res;
}

bool solve() {
    int n;
    if (!(cin >> n))
        return 0;

    static vector<long long> ways = prepare();

    cout << ways[n] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}