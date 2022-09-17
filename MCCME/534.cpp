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

    int w, t;
    cin >> w >> t;

    t %= 2 * w;
    cout << (t <= w ? t : 2 * w - t);
}