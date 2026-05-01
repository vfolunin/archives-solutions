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

    int size, index, limit;
    cin >> size >> index >> limit;
    index--;

    int res = 1e9;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        if (0 < value && value <= limit)
            res = min(res, abs(i - index) * 10);
    }

    cout << res;
}