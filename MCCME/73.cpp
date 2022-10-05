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

    int prev, res = 1;
    cin >> prev;

    for (int i = 1; i < size; i++) {
        int cur;
        cin >> cur;
        res += prev != cur;
        prev = cur;
    }

    cout << res;
}