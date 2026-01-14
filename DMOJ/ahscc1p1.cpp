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

    int percentage, count;
    cin >> percentage >> count;

    int res = max(80 * (count + 1) - percentage * count, 0);

    cout << (res <= 100 ? res : -1);
}