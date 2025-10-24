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

    int n;
    cin >> n;

    vector<vector<int>> ways(n + 1, vector<int>(4));
    for (int i = 1; i <= n; i++) {
        ways[i][0] = 1;
        for (int count = 1; count < 4; count++)
            for (int j = 1; j < i; j++)
                ways[i][count] += ways[j][count - 1];
    }

    cout << ways[n][3];
}