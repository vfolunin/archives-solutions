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

    vector<int> portions = { 300, 1500, 600, 1000, 150 };

    int res = 225;
    for (int portion : portions) {
        int count;
        cin >> count;
        res += count * portion;
    }

    cout << res << "\n";
}