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

    int size, count;
    cin >> size >> count;

    int prev = 0, res = 0;
    for (int i = 0; i < size; i++) {
        int cur;
        cin >> cur;

        res += !prev && cur;

        prev = cur;
    }

    cout << res;
}