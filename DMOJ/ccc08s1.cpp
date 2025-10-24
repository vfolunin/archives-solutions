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

    string res, s;
    int resT = 1e9, t;

    while (cin >> s >> t) {
        if (resT > t) {
            res = s;
            resT = t;
        }
    }

    cout << res;
}