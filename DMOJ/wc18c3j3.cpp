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

    int w;
    cin >> w;

    cout << string(w - 1, '#') << ".\n";
    for (int y = 1; y < w - 1; y++)
        cout << "#" << string(w - 2, '.') << "#\n";
    cout << string(w - 1, '#') << ".\n";
    for (int y = 1; y < w; y++)
        cout << "#" << string(y - 1, '.') << "#" << string(w - y - 1, '.') << "\n";
}