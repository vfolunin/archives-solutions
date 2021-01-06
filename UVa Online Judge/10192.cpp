#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    string a, b;
    getline(cin, a);
    if (!getline(cin, b))
        return 0;

    vector<vector<int>> d(a.size() + 1, vector<int>(b.size() + 1));
    for (int i = 1; i <= a.size(); i++) {
        for (int j = 1; j <= b.size(); j++) {
            if (a[i - 1] == b[j - 1])
                d[i][j] = d[i - 1][j - 1] + 1;
            else
                d[i][j] = max(d[i - 1][j], d[i][j - 1]);
        }
    }

    cout << "Case #" << test << ": ";
    cout << "you can visit at most " << d[a.size()][b.size()] << " cities.\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}