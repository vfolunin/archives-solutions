#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long joseph2(long long size) {
    if (size == 1)
        return 1;
    else if (size % 2)
        return joseph2(size / 2) * 2 + 1;
    else
        return joseph2(size / 2) * 2 - 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long size;
    cin >> size;

    cout << joseph2(size);
}