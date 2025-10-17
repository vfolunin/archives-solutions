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

    int threshold, count, factor;
    cin >> threshold >> count >> factor;

    int res = 0, totalCount = count;
    while (totalCount <= threshold) {
        res++;
        count = count * factor;
        totalCount += count;
    }

    cout << res;
}