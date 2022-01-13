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

    long long blockCount;
    cin >> blockCount;

    long long height = 0;
    while (blockCount >= (height * 2 + 1) * (height * 2 + 1)) {
        blockCount -= (height * 2 + 1) * (height * 2 + 1);
        height++;
    }

    cout << height;
}