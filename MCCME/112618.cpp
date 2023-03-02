#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int rec(int a, int b) {
    static vector<int> memo(4001, -1);
    int &res = memo[a];
    if (res != -1)
        return res;

    if (a > b)
        return res = 0;
    if (a == b)
        return res = 1;

    res = rec(a + 1, b);
    if (a * 3 <= b)
        res += rec(a * 3, b);
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int a, b;
    cin >> a >> b;

    cout << rec(a, b);
}