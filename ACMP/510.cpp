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

    int size;
    cin >> size;

    vector<vector<int>> ways(size + 1, vector<int>(8));
    ways[0][7] = ways[1][3] = ways[1][6] = 1;

    for (int i = 2; i < ways.size(); i++) {
        ways[i][1] = ways[i - 1][6];
        ways[i][2] = ways[i - 1][5];
        ways[i][3] = ways[i - 1][4] + ways[i - 1][7];
        ways[i][4] = ways[i - 1][3];
        ways[i][5] = ways[i - 1][2];
        ways[i][6] = ways[i - 1][1] + ways[i - 1][7];
        ways[i][7] = ways[i - 2][7] + ways[i][1] + ways[i][4];
    }

    cout << ways[size][7];
}