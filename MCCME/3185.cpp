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

    long long res = 1;
    bool found = 0;

    for (int i = 0; i < 10; i++) {
        long long value;
        cin >> value;

        if (value) {
            res *= value;
            found = 1;
        }
    }

    cout << (found ? res : 0);
}