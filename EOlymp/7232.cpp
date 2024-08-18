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

    int a1, a2, a3, b1, b2, b3;
    cin >> a1 >> a2 >> a3 >> b1 >> b2 >> b3;

    int res = 0;

    int delta1 = min(a1, b1);
    a1 -= delta1;
    b1 -= delta1;
    res += delta1;

    int delta2 = min(a2, b2);
    a2 -= delta2;
    b2 -= delta2;
    res += delta2;

    int delta3 = min(a3, b1 + b2);
    a3 -= delta3;
    res += delta3;
    delta3 = min(a1 + a2, b3);
    b3 -= delta3;
    res += delta3;

    res += min(a3, b3);

    cout << res;
}