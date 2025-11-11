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

    int res, factor, count;
    cin >> res >> factor >> count;

    for (int i = 0; i < count; i++)
        res *= factor;

    cout << res;
}