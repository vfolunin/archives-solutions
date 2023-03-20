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

    vector<vector<int>> weight(vertexCount, vector<int>(vertexCount));
    for (int a = 0; a < vertexCount; a++)
        for (int b = 0; b < vertexCount; b++)
            cin >> weight[a][b];

    vector<int> direction(vertexCount);
    for (int &d : direction)
        cin >> d;

    int resWeight = 1e9, resA, resB;
    for (int a = 0; a < vertexCount; a++) {
        for (int b = 0; b < vertexCount; b++) {
            if (!direction[a] && direction[b] && resWeight > weight[a][b]) {
                resWeight = weight[a][b];
                resA = a;
                resB = b;
            }
        }
    }

    cout << resA + 1 << " " << resB + 1;
}