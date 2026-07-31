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

    int divisor, dayCount;
    cin >> divisor >> dayCount;

    int res = dayCount / 7;
    dayCount -= res;
    res += dayCount / divisor;

    cout << res;
}