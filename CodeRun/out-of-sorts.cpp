#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    unordered_set<int> badShifts;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;
        value--;

        badShifts.insert((value - i + size) % size);
    }

    int shift = 0;
    while (badShifts.contains(shift))
        shift++;

    cout << (shift < size ? shift : -1);
}