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

    int targetCount, size;
    cin >> targetCount >> size;

    long long res = 0;
    bool found = 0;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        if (value < targetCount) {
            res += value;
        } else {
            res += targetCount - 1;
            found = 1;
        }
    }

    cout << (found ? res + 1 : -1);
}