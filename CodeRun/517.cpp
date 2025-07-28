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

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int vertexCount;
    cin >> vertexCount;

    vector<int> to(vertexCount);
    for (int &to : to)
        cin >> to;

    for (int v = 0; v != -1; ) {
        if (to[v] == -2) {
            cout << "YES";
            return 0;
        }

        int prevV = v;
        v = to[v];
        to[prevV] = -2;
    }

    cout << "NO";
}