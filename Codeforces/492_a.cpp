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

    int count;
    cin >> count;

    int res = 0, levelCount = 0;
    while (count >= levelCount + res + 1) {
        res++;
        levelCount += res;
        count -= levelCount;
    }

    cout << res;
}