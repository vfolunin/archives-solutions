#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<string> a(size);
    for (string &row : a)
        cin >> row;

    vector<vector<int>> ways(size, vector<int>(size));
    ways[0][0] = a[0][0] == '.';

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (a[i][j] == '.') {
                if (i)
                    ways[i][j] = (ways[i][j] + ways[i - 1][j]) % MOD;
                if (j)
                    ways[i][j] = (ways[i][j] + ways[i][j - 1]) % MOD;
            }
        }
    }

    cout << ways[size - 1][size - 1];
}