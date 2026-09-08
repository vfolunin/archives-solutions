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

    long long h1, w1, h2, w2;
    cin >> h1 >> w1 >> h2 >> w2;

    cout << h1 * w1 - max(min(h1, h2) * min(w1, w2), min(h1, w2) * min(w1, h2));
}