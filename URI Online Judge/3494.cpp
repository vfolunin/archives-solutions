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

    string a, b;
    cin >> a >> b;

    int res = 0;
    for (int i = 0; i < a.size(); i++) {
        int diff = abs(a[i] - b[i]);
        diff = min(diff, 26 - diff);
        res += diff;
    }

    cout << res << "\n";
}