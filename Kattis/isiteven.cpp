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

    int size, power;
    cin >> size >> power;

    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        while (value % 2 == 0 && power) {
            value /= 2;
            power--;
        }
    }

    cout << (!power);
}