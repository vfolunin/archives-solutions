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

    for (int y = 0; y < size; y++) {
        if (size == 1)
            cout << "*\n";
        else
            cout << "*" << string(size - 2, !y || y + 1 == size ? '*' : ' ') << "*\n";
    }
}