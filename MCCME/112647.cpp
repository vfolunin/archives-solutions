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

    vector<vector<int>> hasEdge(vertexCount, vector<int>(vertexCount));
    for (int a = 0; a < vertexCount; a++)
        for (int b = 0; b < vertexCount; b++)
            cin >> hasEdge[a][b];

    vector<string> color(vertexCount);
    for (string &s : color)
        cin >> s;

    vector<int> res(2);
    for (int a = 0; a < vertexCount; a++)
        for (int b = a; b < vertexCount; b++)
            if (hasEdge[a][b])
                res[color[a] != color[b]]++;

    cout << res[0] << " " << res[1];
}