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

    vector<int> price(vertexCount);
    int res = 0;
    for (int &value : price) {
        cin >> value;

        res += value;
    }

    vector<int> outDegree(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;

        outDegree[a - 1]++;
    }

    int maxPrice = 0;
    for (int v = 0; v < vertexCount; v++)
        if (!outDegree[v])
            maxPrice = max(maxPrice, price[v]);

    res -= maxPrice;

    cout << res;
}