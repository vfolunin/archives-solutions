#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("warriors.in", "r", stdin);
    freopen("warriors.out", "w", stdout);

    int size;
    cin >> size;

    int count = (size + 1) / 2;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        count -= value == 1;
    }

    cout << max(count, 0);
}