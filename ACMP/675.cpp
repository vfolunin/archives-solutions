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

    int h, w;
    cin >> h >> w;

    int res = 1e9;
    for (int i = 0; i < h; i++) {
        string s;
        cin >> s;
        res = min<int>(res, count(s.begin(), s.end(), '.'));
    }

    cout << res;
}