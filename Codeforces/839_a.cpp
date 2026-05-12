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

    int size, threshold;
    cin >> size >> threshold;

    int arya = 0, bran = 0;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        arya += value;
        int delta = min(arya, 8);
        arya -= delta;
        bran += delta;

        if (bran >= threshold) {
            cout << i + 1;
            return 0;
        }
    }

    cout << -1;
}