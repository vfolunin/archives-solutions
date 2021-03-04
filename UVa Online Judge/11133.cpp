#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<vector<int>> prepare() {
    vector<vector<int>> ways(45, vector<int>(45));

    for (int start = 0; start < 45; start++) {
        ways[start][start] = 1;

        for (int v = start; v < 45; v++)
            for (int to = v + 1; to < 45; to++)
                if (to % (to - v) == 0)
                    ways[start][to] += ways[start][v];        
    }

    return ways;
}

bool solve() {
    int a, b;
    cin >> a >> b;

    if (!a && !b)
        return 0;

    static vector<vector<int>> ways = prepare();

    cout << a << " " << b << " " << ways[a][b] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}