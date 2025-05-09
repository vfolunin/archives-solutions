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

    int delta = 1, res = 0;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        if (value) {
            res += delta;
            delta = 1;
        } else {
            res -= delta;
            delta *= 2;
        }
    }

    cout << res;
}