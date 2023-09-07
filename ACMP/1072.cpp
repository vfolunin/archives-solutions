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

    if (vertexCount <= 2) {
        cout << 0;
        return 0;
    }

    vector<int> degree(vertexCount);
    for (int i = 0; i < vertexCount - 1; i++) {
        int a, b;
        cin >> a >> b;
        degree[a - 1]++;
        degree[b - 1]++;
    }

    cout << vertexCount - count(degree.begin(), degree.end(), 1);
}