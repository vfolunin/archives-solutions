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

    int size, userCount, totalSize;
    cin >> size >> userCount >> totalSize;

    cout << totalSize / userCount - (size * 6 + 7) / 8;
}