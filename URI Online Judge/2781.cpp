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

    int edgeCount, vertexCount;
    cin >> edgeCount >> vertexCount;

    vector<int> balance(vertexCount);
    int weightSum = 0;

    for (int i = 0; i < edgeCount; i++) {
        int a, w, b;
        cin >> a >> w >> b;
        a--;
        b--;
        balance[a] -= w;
        balance[b] += w;
        weightSum += w;
    }

    int newWeightSum = 0;
    for (int &b : balance)
        newWeightSum += abs(b);
    newWeightSum /= 2;

    cout << (newWeightSum < weightSum ? "S\n" : "N\n");
    cout << newWeightSum << "\n";
}