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

    int target, size;
    cin >> target >> size;

    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        if (value == target) {
            cout << i + 1;
            return 0;
        }
    }

    cout << 0;
}