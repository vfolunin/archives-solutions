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

    int size;
    cin >> size;

    map<string, int> faces = {
        { "Tetrahedron", 4 },
        { "Cube", 6 },
        { "Octahedron", 8 },
        { "Dodecahedron", 12 },
        { "Icosahedron", 20 }
    };

    int res = 0;
    for (int i = 0; i < size; i++) {
        string type;
        cin >> type;

        res += faces[type];
    }

    cout << res;
}