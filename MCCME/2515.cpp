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

    int size, x;
    cin >> size >> x;

    int res = min(x - 1, size - x) + size - 1;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;
        res += value;
    }

    cout << res;
}