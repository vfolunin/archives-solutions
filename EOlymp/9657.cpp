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

    for (string type; cin >> type; ) {
        if (type == "Rectangle") {
            int h, w;
            cin >> h >> w;

            cout << h * w << " " << 2 * (h + w) << "\n";
        } else {
            int size;
            cin >> size;

            cout << size * size << " " << 4 * size << "\n";
        }
    }
}