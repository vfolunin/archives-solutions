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

    vector<vector<long long>> ways(size * 2, vector<long long>(size * 2));
    ways[1][1] = 1;

    for (int y = 1; y < ways.size(); y++)
        for (int x = 1; x < ways.size(); x++)
            if (y - size + 1 <= x && x <= y + size - 1)
                ways[y][x] += ways[y - 1][x - 1] + ways[y - 1][x] + ways[y][x - 1];

    cout << ways.back().back();
}