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

    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    vector<int> order(vertexCount);
    for (int i = 1; i <= edgeCount; i++) {
        int a, b;
        cin >> a >> b;

        if (a > b)
            swap(a, b);

        if (a + 1 == b)
            order[a - 1] = i;
        if (a == 1 && b == vertexCount)
            order.back() = i;
    }

    if (!count(order.begin(), order.end(), 0)) {
        for (int index : order)
            cout << index << "\n";
    } else {
        cout << "impossible";
    }
}