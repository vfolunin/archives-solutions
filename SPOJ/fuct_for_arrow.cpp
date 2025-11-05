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

    if (size <= 2) {
        cout << "accept positive integer greater than 2 only!";
        return 0;
    }

    for (int i = 0; i < size; i++)
        cout << "*" << (i + 1 < size ? " " : "\n");
    for (int i = 1; i * 2 < size; i++)
        cout << string(i * 2, ' ') << "*" << string(size * 2 - 3, ' ') << "*\n";
    for (int i = size / 2 - 1; i; i--)
        cout << string(i * 2, ' ') << "*" << string(size * 2 - 3, ' ') << "*\n";
    for (int i = 0; i < size; i++)
        cout << "*" << (i + 1 < size ? " " : "\n");
}