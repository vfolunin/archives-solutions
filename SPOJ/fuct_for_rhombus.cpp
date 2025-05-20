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

    cout << string((size - 1) * 2, ' ') << "*\n";
    for (int y = 1; y < size; y++)
        cout << string((size - 1 - y) * 2, ' ') << "*" << string(y * 4 - 1, ' ') << "*\n";
    for (int y = size - 2; y > 0; y--)
        cout << string((size - 1 - y) * 2, ' ') << "*" << string(y * 4 - 1, ' ') << "*\n";
    if (size > 1)
        cout << string((size - 1) * 2, ' ') << "*\n";
}