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

    for (int y = 0; y < 4; y++)
        cout << string(w, '#') << "\n";
}