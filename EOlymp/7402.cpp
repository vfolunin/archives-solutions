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

    map<int, int> count;
    int res = 0;

    for (int i = 0; i < size; i++) {
        int value, delta;
        cin >> value >> delta;

        count[value] += delta;
        if (count[res] < count[value])
            res = value;
    }

    cout << res;
}