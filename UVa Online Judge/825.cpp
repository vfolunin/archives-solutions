#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> readInts() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> res;
    int x;
    while (ss >> x)
        res.push_back(x);
    return res;
}

void solve(int test) {
    int h, w;
    cin >> h >> w;
    cin.ignore();

    vector<vector<long long>> paths(h, vector<long long>(w));

    for (int i = 0; i < h; i++) {
        vector<int> v = readInts();
        for (int j = 1; j < v.size(); j++)
            paths[i][v[j] - 1] = -1;
    }

    if (paths[0][0] != -1)
        paths[0][0] = 1;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (paths[i][j] != -1) {
                if (i)
                    paths[i][j] += paths[i - 1][j];
                if (j)
                    paths[i][j] += paths[i][j - 1];
            } else {
                paths[i][j] = 0;
            }
        }
    }

    if (test)
        cout << "\n";
    cout << paths[h - 1][w - 1] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve(i);
}