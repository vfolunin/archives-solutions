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

    int count, left;
    cin >> count >> left;

    if (left <= 1)
        cout << 1;
    else
        cout << min(left, count - left);
}