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

    int index;
    cin >> index;
    index--;

    int size = 1;
    while (index >= (1 << size)) {
        index -= (1 << size);
        size++;
    }

    for (; size; size--) {
        int digit = 4;
        if (index >= (1 << (size - 1))) {
            index -= (1 << (size - 1));
            digit = 7;
        }
        cout << digit;
    }
}