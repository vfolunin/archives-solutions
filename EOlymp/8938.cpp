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

    int h;
    cin >> h;

    for (int y = 0; y < h; y++)
        cout << string(3, '#') << "\n";
}