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

    long long res = 1e18;
    for (int i = 0; i < size; i++) {
        long long time, state;
        cin >> time >> state;

        if (!state)
            res = min(res, time);
    }

    cout << (res != 1e18 ? res : -1);
}