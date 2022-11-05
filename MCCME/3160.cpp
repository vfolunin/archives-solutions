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

    int value, res = 0;

    while (cin >> value)
        if (value % 2 && (!res || res > value))
            res = value;

    cout << res;
}