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

    int s, r;
    cin >> s >> r;

    cout << (s * s <= 2 * r * r ? "fits" : "nope");
}