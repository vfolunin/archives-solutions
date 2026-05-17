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

    vector<int> side(3);
    for (int &side : side)
        cin >> side;

    sort(side.begin(), side.end());

    cout << (side[0] + side[1] > side[2] ? "YES" : "NO");
}