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

    vector<string> g = {
        "GGGGG",
        "G....",
        "G..GG",
        "G...G",
        "GGGGG"
    };

    for (int y = 0; y < g.size() * size; y++) {
        for (int x = 0; x < g.size() * size; x++)
            cout << g[y / size][x / size];
        cout << "\n";
    }
}