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

    vector<int> isSource(vertexCount, 1);

    for (int v = 0; v < vertexCount; v++) {
        int outDegree;
        cin >> outDegree;

        for (int i = 0; i < outDegree; i++) {
            int to;
            cin >> to;

            isSource[to - 1] = 0;
        }
    }

    cout << count(isSource.begin(), isSource.end(), 1);
}