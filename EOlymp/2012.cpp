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

    int prevValue = 1e9, cur = 1, res = 1;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        if (prevValue + 1 == value)
            cur++;
        else
            cur = 1;

        res = max(res, cur);
        prevValue = value;
    }

    cout << res;
}