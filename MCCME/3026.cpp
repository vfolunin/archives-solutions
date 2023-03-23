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

    int h, w;
    cin >> h >> w;

    for (int i = 0; i < 2; i++) {
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++)
                cout << "0 ";
            cout << "\n";
        }
    }
}