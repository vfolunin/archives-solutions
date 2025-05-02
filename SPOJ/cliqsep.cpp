#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int vertexCount, edgeCount, cliqueSize;
    if (!(cin >> vertexCount >> edgeCount >> cliqueSize))
        return 0;

    cout << (cliqueSize % 2 ? "no\n" : "yes\n");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}