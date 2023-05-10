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

    int size, width;
    cin >> size >> width;

    vector<long long> ways(max(size, width) + 1);
    ways[0] = 1;

    for (int i = 1; i < width; i++)
        ways[i] = ways[i - 1] * 2;

    ways[width] = ways[width - 1] * 2 - 1;

    for (int i = width + 1; i < ways.size(); i++)
        ways[i] = ways[i - 1] * 2 - ways[i - width - 1];

    cout << ways[size];
}