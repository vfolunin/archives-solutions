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

    int vertexCount;
    cin >> vertexCount;

    int res = 0;

    for (int v = 1; v <= vertexCount; v++) {
        int degree;
        cin >> degree;

        for (int i = 0; i < degree; i++) {
            int to;
            cin >> to;

            res += v == to;
        }
    }

    cout << res;
}