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

    long long value;
    int opCount;
    cin >> value >> opCount;

    long long res = value;
    for (int i = 0; i < opCount; i++) {
        int d = value % 10;
        value = value / 10 + d * d * d * d * d * 20;
        res = max(res, value);
    }

    cout << res;
}