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

    int value;
    cin >> value;

    int res = 0;
    for (; value; value /= 8)
        res += value % 8 == 1;

    cout << res;
}