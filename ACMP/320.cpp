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

    int h, w;
    cin >> h >> w;

    vector<long long> ways(w + 1);
    ways[0] = 1;

    for (int i = 1; i < ways.size(); i++) {
        ways[i] = ways[i - 1];
        if (i >= h)
            ways[i] += ways[i - h];
    }

    cout << ways[w];
}