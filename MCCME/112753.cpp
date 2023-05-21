#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void rec(int cur, int i, int target, int &res) {
    if (i == 7) {
        res += cur == target;
        return;
    }
    rec(cur + i, i + 1, target, res);
    rec(cur - i, i + 1, target, res);
    rec(cur * i, i + 1, target, res);
    rec(cur / i, i + 1, target, res);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int target;
    cin >> target;

    int res = 0;
    rec(1, 2, target, res);

    cout << res;
}