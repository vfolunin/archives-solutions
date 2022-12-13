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

    vector<vector<int>> ways(n + 1, vector<int>(3));
    ways[1] = { 1, 1, 1 };

    for (int i = 2; i < ways.size(); i++) {
        ways[i][0] = ways[i - 1][0] + ways[i - 1][1] + ways[i - 1][2];
        ways[i][1] = ways[i - 1][0] + ways[i - 1][2];
        ways[i][2] = ways[i - 1][0] + ways[i - 1][1] + ways[i - 1][2];
    }

    cout << ways[n][0] + ways[n][1] + ways[n][2];
}