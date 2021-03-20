#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    string line;
    cin >> line;

    int res = 0;
    for (int i = 0; i < line.size(); i++) {
        if (line[i] != '-')
            continue;
        if (i + 1 < line.size() && (line[i + 1] == 'B' || line[i + 1] == 'S'))
            continue;
        if (i + 2 < line.size() && line[i + 2] == 'B')
            continue;
        if (i - 1 >= 0 && line[i - 1] == 'S')
            continue;
        res++;
    }

    cout << "Case " << test << ": " << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}