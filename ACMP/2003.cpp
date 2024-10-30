#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int rec(int i, int count, int threshold) {
    if (i == 7)
        return count >= threshold;

    int res = 0;
    for (int value = 0; value < 7; value++)
        res += rec(i + 1, count + !value, threshold);
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int threshold;
    cin >> threshold;

    cout << rec(0, 0, threshold);
}