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

    int h1, w1, h2, w2;
    cin >> h1 >> w1 >> h2 >> w2;

    cout << 2 * min(h1 + h2 + max(w1, w2), max(h1, h2) + w1 + w2);
}