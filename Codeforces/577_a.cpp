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

    int size, value;
    cin >> size >> value;

    int res = 0;
    for (int y = 1; y <= size; y++)
        res += value % y == 0 && value / y <= size;

    cout << res;
}