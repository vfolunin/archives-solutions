#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int rec(int i, int size, int cur, int target) {
    if (i == size)
        return cur == target;

    int res = 0;
    for (int c = 1; c <= 26; c++)
        res += rec(i + 1, size, cur * 13 + c, target);
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, target;
    cin >> size >> target;

    cout << rec(0, size, 0, target);
}