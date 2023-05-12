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

    long long product = 1;
    bool found = 0;

    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        if (value) {
            product *= value;
            found = 1;
        }
    }

    cout << (found ? product : 0);
}