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

    int w, h;
    cin >> w >> h;

    int size = min(w, h);

    cout << size + 1 << "\n";
    for (int x = 0, y = size; y >= 0; x++, y--)
        cout << x << " " << y << "\n";
}