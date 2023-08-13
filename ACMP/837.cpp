#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    long long vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    cout << (vertexCount > 1 && edgeCount <= (vertexCount - 1) * (vertexCount - 2) / 2 ? "Yes\n" : "No\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}