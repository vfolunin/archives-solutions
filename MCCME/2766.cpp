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

    int len, v1, v2, t;
    cin >> len >> v1 >> v2 >> t;

    int dist = (v1 + v2) * t % len;

    cout << min(dist, len - dist);
}