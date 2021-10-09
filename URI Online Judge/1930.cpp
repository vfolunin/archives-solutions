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

    int res = -3;

    for (int i = 0; i < 4; i++) {
        int x;
        cin >> x;

        res += x;
    }

    cout << res << "\n";
}