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

    int value, count;
    cin >> value >> count;

    int res = 0;
    for (int i = 0; i <= count; i++) {
        res += value;
        value *= 10;
    }

    cout << res;
}