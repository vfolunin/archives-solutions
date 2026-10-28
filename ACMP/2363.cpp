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

    int length, size;
    cin >> length >> size;

    size *= 1024 * 8;
    int r = 1 << (size / length);
    int l = r / 2 + 1;

    cout << l << " " << r;
}