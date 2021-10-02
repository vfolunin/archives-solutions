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

    int res = 0;
    for (int i = 0; i < 6; i++) {
        double x;
        cin >> x;
        res += x > 0;
    }

    cout << res << " valores positivos\n";
}