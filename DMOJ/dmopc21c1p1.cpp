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

    long long a = 0, b = 0;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        if (value % 2 == 0)
            a += value / 2;
        else
            b += (value + 1) / 2;
    }

    cout << (a > b ? "Duke\n" : "Alice\n");
}