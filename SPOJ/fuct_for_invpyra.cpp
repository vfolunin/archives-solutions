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
        cout << string(y * 2, ' ');
        for (int i = 1; i < (size - y) * 2; i++)
            cout << "* ";
        cout << "\n";
    }
}