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

    for (int y = 0; y < h; y++) {
        if (w == 1)
            cout << "*\n";
        else
            cout << "*" << string(w - 2, !y || y + 1 == h ? '*' : ' ') << "*\n";
    }
}