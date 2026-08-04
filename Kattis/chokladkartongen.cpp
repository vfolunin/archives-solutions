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

    int size;
    cin >> size;

    int prev, cur = 1e9, res = 0;
    for (int i = 0; i < size; i++) {
        prev = cur;
        cin >> cur;

        res += prev < cur;
    }

    cout << res;
}