#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);

    int size;
    cin >> size;

    int res = 1;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        res += value;
    }

    cout << res;
}